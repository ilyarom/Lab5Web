#include "stdafx.h"
#include "QueryHandler.h"

int main()
{
	try
	{
		CQueryHandler server;
		server.StartQueryHandle();
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
