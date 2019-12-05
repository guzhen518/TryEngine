#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "log4cplus/loggingmacros.h"
#include "log4cplus/loglevel.h"
#include "log4cplus/ndc.h"


#include <windows.h>

#define MY_LOG_FILE_PATH "logconfig.property"

int main(int argc, char* argv[])
{
	log4cplus::initialize();
	log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_FILE_PATH));
	log4cplus::Logger rootLog = log4cplus::Logger::getRoot();
	char test[16] = "test";

	LOG4CPLUS_FATAL(rootLog, "DeleteService failed,errCode=[" << 1 << "]");    //打印级别为FATAL的日志
	LOG4CPLUS_DEBUG(rootLog, " Service is removed");    //打印级别为DEBUG的日志

	system("pause");


	return 0;
}