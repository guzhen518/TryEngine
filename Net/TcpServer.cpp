#include "TcpServer.h"
#include "SocketOpt.h"

TryTcpServer::TryTcpServer()
{


}

TryTcpServer::~TryTcpServer()
{


}

bool TryTcpServer::Start()
{
	if ( !Common_NetStartUP() )	{
		return false;
	}

	return true;
}

bool TryTcpServer::Run()
{
	return false;
}


bool TryTcpServer::Stop()
{
	return false;

}
