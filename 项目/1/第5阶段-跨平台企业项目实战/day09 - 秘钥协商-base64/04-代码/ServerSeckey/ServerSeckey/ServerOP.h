#pragma once
#include <map>
#include "TcpServer.h"
#include "Message.pb.h"
// 处理客户端请求
class ServerOP
{
public:
	enum KeyLen {Len16=16, Len24=24, Len32=32};
	ServerOP(string json);
	// 启动服务器
	void startServer();
	// 线程工作函数 -> 推荐使用
	static void* working(void* arg);
	// 友元破坏了类的封装
	friend void* workHard(void* arg);
	// 秘钥协商
	string seckeyAgree(RequestMsg* reqMsg);
	~ServerOP();

private:
	string getRandKey(KeyLen len);

private:
	string m_serverID;	// 当前服务器的ID
	unsigned short m_port;
	map<pthread_t, TcpSocket*> m_list;
	TcpServer *m_server = NULL;
};

void* workHard(void* arg);

