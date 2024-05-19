#include "ThreadPool.h"
#include <iostream>
#include <string.h>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include "TaskQueue.h"
using namespace std;

const int DEFAULT_TIME = 10;                /*10s检测一次*/
const int MIN_WAIT_TASK_NUM = 10;           /*如果queue_size > MIN_WAIT_TASK_NUM 添加新的线程到线程池*/
const int DEFAULT_THREAD_VARY = 10;         /*每次创建和销毁线程的个数*/

ThreadPool::ThreadPool(int min, int max)
{
	// 实例化任务队列
	task_queue = new TaskQueue;
	// 获取单例日志对象
	m_log = Logger::getInstance();

	do 
	{
		min_thr_num = min;
		max_thr_num = max;
		busy_thr_num = 0;
		live_thr_num = min_thr_num;               /* 活着的线程数 初值=最小线程数 */

		/* 根据最大线程上限数， 给工作线程数组开辟空间, 并清零 */
		threads = new pthread_t[sizeof(pthread_t) * max_thr_num];
		if (threads == NULL) 
		{
			m_log->Log("malloc threads fail", __FILE__, __LINE__);
			break;
		}
		memset(threads, 0, sizeof(pthread_t) * max_thr_num);

		/* 初始化互斥琐、条件变量 */
		if (pthread_mutex_init(&(lock), NULL) != 0
			|| pthread_mutex_init(&(thread_counter), NULL) != 0
			|| pthread_cond_init(&(queue_not_empty), NULL) != 0)
		{
			m_log->Log("init the lock or cond fail", __FILE__, __LINE__);
			break;
		}

		/* 启动 min_thr_num 个 work thread */
		for (int i = 0; i < min_thr_num; i++) 
		{
			// 创建并启动工作的线程
			pthread_create(&threads[i], NULL, threadWorking, this);
			string log = "start thread: " + to_string((unsigned int)threads[i]);
			m_log->Log(log, __FILE__, __LINE__);
		}
		// 创建并启动管理者线程
		pthread_create(&(adjust_tid), NULL, threadManager, this);
	} while (0);
}


ThreadPool::~ThreadPool()
{
	// 释放资源
	if (task_queue)
	{
		delete task_queue;
	}
	// 销毁锁/条件变量
}

void * ThreadPool::threadWorking(void * arg)
{
	ThreadPool *pool = (ThreadPool *)arg;

	while (true) {
		/* Lock must be taken to wait on conditional variable */
		/*刚创建出线程，等待任务队列里有任务，否则阻塞等待任务队列里有任务后再唤醒接收任务*/
		pthread_mutex_lock(&(pool->lock));

		/*task number == 0 说明没有任务，调 wait 阻塞在条件变量上, 若有任务，跳过该while*/
		while (pool->task_queue->taskNumber() == 0) 
		{
			string log = "thread:" + to_string((unsigned int)pthread_self()) + " is waiting";
			pool->m_log->Log(log, __FILE__, __LINE__);
			pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));

			/*清除指定数目的空闲线程，如果要结束的线程个数大于0，结束线程*/
			if (pool->wait_exit_thr_num > 0) 
			{
				pool->wait_exit_thr_num--;

				/*如果线程池里线程个数大于最小值时可以结束当前线程*/
				if (pool->live_thr_num > pool->min_thr_num) 
				{
					log = "thread:" + to_string((unsigned int)pthread_self()) + " is exiting";
					pool->m_log->Log(log, __FILE__, __LINE__);
					pool->live_thr_num--;
					pthread_mutex_unlock(&(pool->lock));
					pthread_exit(NULL);
				}
			}
		}
		pthread_mutex_unlock(&(pool->lock));

		/*从任务队列里获取任务, 是一个出队操作*/
		Task task = pool->task_queue->takeTask();
		/*执行任务*/
		string log = "thread:" + to_string((unsigned int)pthread_self()) + " is start working...";
		pool->m_log->Log(log, __FILE__, __LINE__);
		pthread_mutex_lock(&(pool->thread_counter));                            /*忙状态线程数变量琐*/
		pool->busy_thr_num++;                                                   /*忙状态线程数+1*/
		pthread_mutex_unlock(&(pool->thread_counter));
		// 执行处理动作
		(*(task.function))(task.arg);                                           /*执行回调函数任务*/
		//task.function(task.arg);                                              /*执行回调函数任务*/

		/*任务结束处理*/
		log = "thread:" + to_string((unsigned int)pthread_self()) + " is end working...";
		pool->m_log->Log(log, __FILE__, __LINE__);
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num--;                                       /*处理掉一个任务，忙状态数线程数-1*/
		pthread_mutex_unlock(&(pool->thread_counter));
	}

	pthread_exit(NULL);
	return nullptr;
}

void * ThreadPool::threadManager(void * arg)
{
	ThreadPool *pool = (ThreadPool*)arg;
	while (true) 
	{
		sleep(DEFAULT_TIME);                                    /*定时 对线程池管理*/
		pthread_mutex_lock(&(pool->lock));
		size_t queue_size = pool->task_queue->taskNumber();        /* 关注 任务数 */
		int live_thr_num = pool->live_thr_num;                  /* 存活 线程数 */
		pthread_mutex_unlock(&(pool->lock));

		pthread_mutex_lock(&(pool->thread_counter));
		int busy_thr_num = pool->busy_thr_num;                  /* 忙着的线程数 */
		pthread_mutex_unlock(&(pool->thread_counter));

		/* 创建新线程 算法： 任务数大于最小线程池个数, 且存活的线程数少于最大线程个数时 如：30>=10 && 40<100*/
		if (queue_size >= MIN_WAIT_TASK_NUM && 
			live_thr_num < pool->max_thr_num) 
		{
			pthread_mutex_lock(&(pool->lock));
			int add = 0;

			/*一次增加 DEFAULT_THREAD 个线程*/
			for (int i = 0; i < pool->max_thr_num && add < DEFAULT_THREAD_VARY
				&& pool->live_thr_num < pool->max_thr_num; i++) 
			{
				if (pool->threads[i] == 0 || !pool->threadIsAlive(pool->threads[i]))
				{
					pthread_create(&(pool->threads[i]), NULL, threadWorking, arg);
					add++;
					pool->live_thr_num++;
				}
			}

			pthread_mutex_unlock(&(pool->lock));
		}

		/* 销毁多余的空闲线程 算法：忙线程X2 小于 存活的线程数 且 存活的线程数 大于 最小线程数时*/
		if ((busy_thr_num * 2) < live_thr_num  &&  live_thr_num > pool->min_thr_num) 
		{
			/* 一次销毁DEFAULT_THREAD个线程, 隨機10個即可 */
			pthread_mutex_lock(&(pool->lock));
			pool->wait_exit_thr_num = DEFAULT_THREAD_VARY;      /* 要销毁的线程数 设置为10 */
			pthread_mutex_unlock(&(pool->lock));

			for (int i = 0; i < DEFAULT_THREAD_VARY; i++) 
			{
				/* 通知处在空闲状态的线程, 他们会自行终止*/
				pthread_cond_signal(&(pool->queue_not_empty));
			}
		}
	}

	return nullptr;
}

/*
  #include <signal.h>
  int pthread_kill(pthread_t threadId,int signal);
	1. 该函数可以用于向指定的线程发送信号：
	2. 如果线程内不对信号进行处理，则调用默认的处理程式，如SIGQUIT会退出终止线程，
	   SIGKILL会杀死线程等等,可以调用signal(SIGQUIT, sig_process_routine)
	   来自定义信号的处理程序。
	3. 第二个参数信号值为0时，是一个被保留的信号，一般用这个保留的信号测试线程是否存在
	4. 返回值:
		 - 0:调用成功。
		 - ESRCH：线程不存在。
		 - EINVAL：信号不合法。
*/
bool ThreadPool::threadIsAlive(pthread_t tid)
{

	int kill_rc = pthread_kill(tid, 0);
	if (kill_rc == ESRCH) 
	{
		return false;
	}
	return true;
}

void ThreadPool::addPoolTask(Task & task)
{
	/*添加任务到任务队列里*/
	task_queue->addTask(task);
	/*添加完任务后，队列不为空，唤醒线程池中 等待处理任务的线程*/
	pthread_cond_signal(&queue_not_empty);
}
