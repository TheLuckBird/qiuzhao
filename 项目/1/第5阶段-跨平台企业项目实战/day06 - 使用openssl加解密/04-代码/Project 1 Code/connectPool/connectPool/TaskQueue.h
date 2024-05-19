#pragma once
#include <queue>
#include <pthread.h>
#include <string>
#include <iostream>
#define LOG
// 任务结构体
struct Task
{
	Task()
	{
		function = nullptr;
		arg = nullptr;
	}
	void *(*function)(void *);          /* 函数指针，回调函数 */
	void *arg;                          /* 上面函数的参数 */
};

typedef void* (*callback)(void*);
// 任务队列类
class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();
	// 往任务队列中添加任务
	void addTask(Task &task);
	void addTask(callback func, void* arg);

	// 获取当前队列中的任务数量
	inline size_t taskNumber()
	{
		return m_queue.size();
	}

	// 从队列中取出一个任务
	Task takeTask();

	// 打印错误信息
	inline void printLog(std::string str)
	{
#ifdef LOG
		std::cout << "File[" << __FILE__ << "], Line[" << __LINE__
			<< "], Infomation[" << str << "]" << std::endl;
#endif
	}

private:
	pthread_mutex_t m_mutex;	// 互斥锁
	std::queue<Task> m_queue;
};

