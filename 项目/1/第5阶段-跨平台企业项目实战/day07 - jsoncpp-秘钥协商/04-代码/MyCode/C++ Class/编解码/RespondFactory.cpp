#include "RespondFactory.h"

RespondFactory::RespondFactory(std::string enc) : CodecFactory()
{
	m_flag = false;
	m_encStr = enc;
}

RespondFactory::RespondFactory(RespondInfo * info) : CodecFactory()
{
	m_flag = true;
	m_info = info;
}

Codec * RespondFactory::createCodec()
{
	Codec* codec = NULL;
	if (m_flag)
	{
		codec = new RespondCodec(m_info);
	}
	else
	{
		codec = new RespondCodec(m_encStr);
	}
	return codec;
}


RespondFactory::~RespondFactory()
{
}
