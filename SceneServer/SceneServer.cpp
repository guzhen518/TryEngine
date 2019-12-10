#include <windows.h>
#include "../Common/TryLog.h"


int main(int argc, char* argv[])
{
	g_TryLogger->init();

	TRACE_DEBUG("this is debug");
	TRACE_ERROR("this is error");
	system("pause");
	return 0;
}