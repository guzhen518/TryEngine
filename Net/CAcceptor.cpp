#include "SocketOpt.h"

bool Common_NetStartUP()
{
	WSADATA wsaData;
	if ( WSAStartup(0x202, &wsaData)  != 0 )
	{
		return false;
	}

	return true;
}

bool Common_CreateTcpSocket(TrySocket* pTrySocket)
{
	TrySocket sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_ATOM == sock )
	{
		return false;
	}

	*pTrySocket = sock;

	return true;
}

bool Common_CreateUdpSocket(TrySocket* pTrySocket)
{
	TrySocket sock = socket(AF_INET, SOCK_DGRAM, 0);
	if ( INVALID_ATOM == sock )
	{
		return false;
	}
	
	*pTrySocket = sock;
	return true;

}


bool Common_BindSocket(TrySocket sockHandle, const char* ip, int nPort)
{
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;	//设置协议类型  AF_INET:V4  AF_INET6:V6
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons((u_short)nPort);
	
	int nResult = bind(sockHandle, (const sockaddr*)&addr, sizeof(addr));
	if (nResult == SOCKET_ERROR )
	{
		return false;
	}

	return true;
}


bool Common_CloseSocket(TrySocket sockHandle)
{

	int result = closesocket(sockHandle);
	if (result == SOCKET_ERROR )
	{
		return false;
	}

	return true;
}



