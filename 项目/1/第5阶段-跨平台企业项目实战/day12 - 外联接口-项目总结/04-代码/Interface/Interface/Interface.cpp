#include "Interface.h"
#include <json/json.h>
#include <fstream>
#include "SecKeyShm.h"
#include "AesCrypto.h"
using namespace std;

Interface::Interface(string json)
{
	// 解析json文件
	// 1. 得到流对象 -> 读文件
	ifstream ifs(json);
	// 2. 创建json Reader 
	Json::Reader rd;
	// 3. 调用Reader对象 parse, 初始化一个Value对象
	Json::Value root;
	rd.parse(ifs, root);
	// 4. 对Value对象中的数据
	string shmkey = root["shmkey"].asString();
	string serverID = root["serverID"].asString();
	string clientID = root["clientID"].asString();
	int maxNode = root["maxNode"].asInt();

	// 读共享内存
	SecKeyShm shm(shmkey, maxNode);
	// 得到秘钥
	NodeSHMInfo node = shm.shmRead(clientID, serverID);
	m_key = string(node.seckey);
}


Interface::~Interface()
{
}

// "hello,world"
string Interface::encryptData(string data)
{
	// data -> 要加密的数据
	string head = "666 ";
	string str = head + data;	// 666helloworld
	AesCrypto aes(m_key);
	string ret = aes.aesCBCEncrypt(str);
	return ret;
}

string Interface::decryptData(string data)
{
	AesCrypto aes(m_key);
	return aes.aesCBCDecrypt(data);
}
