#include <cstdio>
#include "ServerOP.h"

int main()
{
	ServerOP op("config.json");
	op.startServer();

    return 0;
}