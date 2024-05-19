#pragma once
#include "Codec.h"
#include "msg.pb.h"
#include <iostream>
using namespace std;

struct RequestInfo
{
	int cmd;
	string clientID;
	string serverID;
	string sign;
	string data;
};

class RequestCodec :
	public Codec
{
public:
	RequestCodec();
	RequestCodec(string encstr);
	RequestCodec(RequestInfo *info);
	void initMessage(string encstr);
	void initMessage(RequestInfo *info);
	string encodeMsg();
	void* decodeMsg();
	~RequestCodec();

private:
	string m_encStr;
	RequestMsg m_msg;
};

