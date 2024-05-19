#include "ServerOP.h"
#include "TcpServer.h"
#include "TcpSocket.h"
#include <unistd.h>
#include <string>
#include <fstream>
#include "RespondCodec.h"
#include "RespondFactory.h"
#include "RsaCrypto.h"
#include "Hash.h"
#include <json/json.h>

using namespace std;
using namespace Json;

/*
	{
		"Port":9898
	}
*/
ServerOP::ServerOP(string json)
{
	// 解析json文件, 读文件 -> Value
	ifstream ifs(json);
	Reader r;
	Value root;
	r.parse(ifs, root);
	// 将root中的键值对value值取出
	m_serverID = root["ServerID"].asString();
	m_port = root["Port"].asInt();
}


void ServerOP::startServer()
{
	TcpServer * s = new TcpServer;
	s->setListen(m_port);
	while (1)
	{
		cout << "等待客户端连接...." << endl;
		TcpSocket* tcp = s->acceptConn();
		if (tcp == NULL)
		{
			continue;
		}
		cout << "客户端连接成功...." << endl;
		// 创建子线程
		pthread_t tid;
		// 这个回调可以是类的静态函数, 类的友元函数, 普通的函数
		// 友元的类的朋友, 但是不属于这个类
		// 友元函数可以访问当前类的私有成员
		pthread_create(&tid, NULL, workHard, this);
		m_list.insert(make_pair(tid, tcp));
	}
}

void * ServerOP::working(void * arg)
{
	return nullptr;
}

string ServerOP::seckeyAgree(RequestMsg* msg)
{
	RespondInfo info;
	ofstream ofs("public.pem");
	ofs << msg->data();
	// 0. 检验签名
	RsaCrypto rsa;
	Hash h(T_SHA1);
	h.addData(msg->data());
	bool bl = rsa.rsaVerify(h.result(), msg->sign());
	if (!bl)
	{
		info.status = false;
		cout << "签名校验失败!!!" << endl;
	}
	else
	{
		// 1. 生成随机字符串
		string randStr = getRandStr(16);
		// 2. 通过公钥加密
		string secStr = rsa.rsaPubKeyEncrypt(randStr);
		// 3. 初始化回复的数据
		// 4. 序列化
		info.clientID = msg->clientid();
		info.serverID = m_serverID;
		info.seckeyID = 1;
		info.status = true;
	}

	CodecFactory* factory = new RespondFactory(&info);
	Codec* c = factory->createCodec();
	string data = c->encodeMsg();
	// 5. 发送数据
	return data;
}

ServerOP::~ServerOP()
{
}

void* workHard(void * arg)
{
	sleep(1);
	ServerOP* op = (ServerOP*)arg;
	// 1. 接收客户端数据 -> 编码
	TcpSocket* tcp = op->m_list[pthread_self()];
	string msg = tcp->recvMsg();
		
	// 2. 反序列化 -> 得到原始数据 RequestMsg 类型
	CodecFactory* factory = new RespondFactory(msg);
	Codec* c = factory->createCodec();
	RequestMsg* req = (RequestMsg*)c->decodeMsg();

	// 3. 取出数据
	// 判断客户端是什么请求
	string data;
	switch (req->cmdtype())
	{
	case 1:
		// 秘钥协商
		data = op->seckeyAgree(req);
		break;
	case 2:
		// 秘钥校验
		break;
	default:
		break;
	}
	tcp->sendMsg(data);

	return NULL;
}

string ServerOP::getRandStr(int num)
{
	srand(time(NULL));	// 以当前时间为种子
	string retStr = string();
	char* buf = "~`@#$%^&*()_+=-{}[];':";
	for (int i = 0; i < num; ++i)
	{
		int flag = rand() % 4;
		switch (flag)
		{
		case 0:	// 0-9
			retStr.append(1, rand() % 10 + '0');
			break;
		case 1:	// a-z
			retStr.append(1, rand() % 26 + 'a');
			break;
		case 2:	// A-Z
			retStr.append(1, rand() % 26 + 'A');
			break;
		case 3:	// 特殊字符
			retStr.append(1, buf[rand() % strlen(buf)]);
			break;
		}
	}
	return retStr;
}
