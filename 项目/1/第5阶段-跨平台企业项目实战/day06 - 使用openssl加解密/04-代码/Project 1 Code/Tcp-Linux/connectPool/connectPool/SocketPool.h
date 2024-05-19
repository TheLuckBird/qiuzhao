#pragma once
#include "TcpSocket.h"
#include <pthread.h>
#include <queue>
// 套接字连接池
class SocketPool
{
public:
	SocketPool(string ip, unsigned short port, int capacity);
	// 从连接池中获取一条连接
	TcpSocket* getConnect();
	// 将连接放回到连接池中
	void putConnect(TcpSocket* tcp, bool isValid = true);
	// 判断连接池是否为空
	inline bool isEmpty();
	~SocketPool();
private:
	void createConnect();

private:
	string m_ip;				// 服务器IP
	int m_capacity;				// 连接池最大容量
	int m_nodeNumber;
	unsigned short m_port;		// 服务器端口
	queue<TcpSocket*> m_list;	// 存储连接的队列
	pthread_mutex_t m_mutex;
};

