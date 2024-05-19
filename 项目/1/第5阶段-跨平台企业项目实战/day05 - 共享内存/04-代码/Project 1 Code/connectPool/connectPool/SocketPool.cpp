#include "SocketPool.h"
#include <iostream>
using namespace std;

SocketPool::SocketPool(string ip, unsigned short port, int capacity) :
	m_capacity(capacity),
	m_nodeNumber(capacity),
	m_ip(ip),
	m_port(port)
{
	pthread_mutex_init(&m_mutex, NULL);
	// 创建连接池中需要的连接
	createConnect();
}

TcpSocket * SocketPool::getConnect()
{
	if (m_list.empty())
	{
		return NULL;
	}
	pthread_mutex_lock(&m_mutex);
	// 取出队头连接
	TcpSocket* socket = m_list.front();
	// 弹出取出的连接
	m_list.pop();
	cout << "connect size: " << m_list.size() << endl;
	pthread_mutex_unlock(&m_mutex);
	return socket;
}


void SocketPool::putConnect(TcpSocket * tcp, bool isValid)
{
	pthread_mutex_lock(&m_mutex);
	// 判断连接是否可用
	if (isValid)
	{
		// 放回连接池中
		m_list.push(tcp);
		cout << "放回的连接可用√√√√√√√√" << m_list.size() << endl;
	}
	else
	{
		cout << "连接不可用XXXXXXXX" << m_list.size() << endl;
		// 关闭坏掉的连接, 并释放对象
		tcp->disConnect();
		delete tcp;
		// 创建新的连接
		m_nodeNumber = m_list.size() + 1;
		createConnect();
	}
	cout << "connect size: " << m_list.size() << endl;
	pthread_mutex_unlock(&m_mutex);
}

inline bool SocketPool::isEmpty()
{
	return m_list.empty() == true ? true : false;
}

SocketPool::~SocketPool()
{
	// 销毁互斥锁
	pthread_mutex_destroy(&m_mutex);
	// 关闭连接, 释放套接字对象
	while (m_list.size())
	{
		TcpSocket* t = m_list.front();
		t->disConnect();
		delete t;
		m_list.pop();
	}
}

void SocketPool::createConnect()
{
	cout << " == current list size: " << m_list.size() << endl;
	cout << "=== 容量: " << m_nodeNumber << endl;
	if (m_list.size() >= m_nodeNumber)
	{
		return;
	}
	// 创建socket通信对象
	TcpSocket* tcp = new TcpSocket;
	// 连接服务器
	int ret = tcp->connectToHost(m_ip, m_port);
	if (ret == 0)
	{
		m_list.push(tcp);
		cout << "create new +++++ connect size: " << m_list.size() << endl;
	}
	else
	{
		delete tcp;
	}
	// 递归创建连接
	createConnect();
}
