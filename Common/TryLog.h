#ifndef _TRY_ENTINE_LOG_H_
#define _TRY_ENTINE_LOG_H_

#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "log4cplus/loggingmacros.h"
#include "log4cplus/loglevel.h"
#include "log4cplus/fileappender.h"
#include "log4cplus/ndc.h"


#define MY_LOG_FILE_PATH "logconfig.property"



#define TRACE_DEBUG(log)	g_TryLogger->DebugLog((log), (__FILE__), (__LINE__ ))
#define TRACE_ERROR(log)	g_TryLogger->ErrorLog((log), (__FILE__), (__LINE__ ))
#define TRACE_INFO(log)		g_TryLogger->InfoLog((log), (__FILE__), (__LINE__ ))
#define TRACE_WARN(log)		g_TryLogger->WarnLog((log), (__FILE__), (__LINE__ ))


class TryLogger
{

public:
	TryLogger() 
	{
	
	}


	bool init() 
	{
		log4cplus::initialize();
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_FILE_PATH));
		m_rootLog = log4cplus::Logger::getRoot();
		return true;
	}

	~TryLogger() {

	}

public:
	void DebugLog(const std::string& strLog, const std::string strFile, int nLine)
	{
		std::stringstream ssLogData;
		ssLogData << "[" << strFile << ":" << nLine << "] " << strLog;
		LOG4CPLUS_DEBUG(m_rootLog, ssLogData.str());
	}

	void ErrorLog(const std::string& strLog, const std::string strFile, int nLine)
	{
		//LOG4CPLUS_DISABLE_ERROR
		std::stringstream ssLogData;
		ssLogData << "[" << strFile << ":" << nLine << "] " << strLog;
		LOG4CPLUS_ERROR(m_rootLog, ssLogData.str());
	}

	void InfoLog(const std::string& strLog, const std::string strFile, int nLine)
	{
		//LOG4CPLUS_DISABLE_ERROR
		std::stringstream ssLogData;
		ssLogData << "[" << strFile << ":" << nLine << "] " << strLog;
		LOG4CPLUS_INFO(m_rootLog, ssLogData.str());
	}

	void WarnLog(const std::string& strLog, const std::string strFile, int nLine)
	{
		//LOG4CPLUS_DISABLE_ERROR
		std::stringstream ssLogData;
		ssLogData << "[" << strFile << ":" << nLine << "] " << strLog;
		LOG4CPLUS_WARN(m_rootLog, ssLogData.str());
	}

private:
	log4cplus::Logger m_rootLog;
	
};

static TryLogger* g_TryLogger = new TryLogger;



#endif
