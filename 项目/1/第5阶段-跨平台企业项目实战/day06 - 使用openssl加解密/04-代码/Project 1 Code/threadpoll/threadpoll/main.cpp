#include <cstdio>
#include <unistd.h>
#include <string>
#include "ThreadPool.h"
#include "Logger.h"
using namespace std;

void *process(void *arg)
{
	int number = *(int*)arg;
	Logger* log = Logger::getInstance();
	string str = "thread:" + to_string((unsigned int)pthread_self()) + 
		" is end working on task, number: " + to_string(number);
	log->Log(str, __FILE__, __LINE__);

	sleep(1);
	str = "task " + to_string(number) + " is end";
	log->Log(str, __FILE__, __LINE__);

	return NULL;
}

int main()
{
//	Logger::getInstance()->setDevice(Logger::FILE);
//	Logger::getInstance()->setEnableLevel(Logger::CRITICAL);
	// 1. 创建线程池对象
	ThreadPool pool(2, 8);
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; ++i)
	{
		Task task;
		task.function = process;
		task.arg = (void*)&array[i];
		pool.addPoolTask(task);
	}
	while (1)
	{
		sleep(10000000);
	}
    return 0;
}