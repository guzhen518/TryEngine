#include <windows.h>
#include "../Common/TryLog.h"


int main(int argc, char* argv[])
{
	g_TryLogger->init();

	while (1)
	{
		::Sleep(1000);
		TRACE_DEBUG("THIS IS DEBUG");
	}
	
	system("pause");


	return 0;
}