#include <cstdio>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include "SocketPool.h"
#include "ThreadPool.h"
using namespace std;

void* working(void* arg)
{
	SocketPool* pool = (SocketPool*)arg;
	TcpSocket* tcp = NULL;
	while (tcp == NULL)
	{
		tcp = pool->getConnect();
		usleep(100);
	}
	// 通信
	int i = 10;
	static int num = 0;
	while (i--)
	{
		// 发送数据
		string str = "hello, server" + to_string(num++);
		tcp->sendMsg(str);
		// 接收数据
		string msg = tcp->recvMsg();
		if (msg.empty())
		{
			pool->putConnect(tcp, false);
			return NULL;
		}
		cout << "server say: " << msg << endl;
		sleep(1);
	}
	// 放回连接
	pool->putConnect(tcp);

	return NULL;
}

int main()
{
	// 创建连接池对象
	SocketPool cpool("127.0.0.1", 9999, 5);
	// 创建线程池对象
	ThreadPool tpool(2, 8);
	for (int i = 0; i < 10; ++i)
	{
#if 0
		pthread_t tid;
		pthread_create(&tid, NULL, working, &cpool);
#else
		Task task;
		task.function = working;
		task.arg = &cpool;
		tpool.addPoolTask(task);
#endif
	}
	sleep(10000);
    printf("hello from connectPool!\n");

    return 0;
}