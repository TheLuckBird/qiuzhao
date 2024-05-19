#pragma once
#include "CodecFactory.h"
#include "Response.h"
#include <iostream>

class RespondFactory :
	public CodecFactory
{
public:
	RespondFactory(std::string enc);
	RespondFactory(RespondInfo* info);
	Codec* createCodec();

	~RespondFactory();

private:
	bool m_flag;
	std::string m_encStr;
	RespondInfo* m_info;
};

