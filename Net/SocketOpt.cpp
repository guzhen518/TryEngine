#include "SocketOpt.h"


bool Common_NetStartUP()
{
#ifdef _WINDOWS
	WSADATA wsaData;
	if (WSAStartup(0x202, &wsaData) != 0 ) {
		return false;
	}

#endif
	
	return true;
}

bool Common_NetStopUP()
{
	return false;
}

bool Common_CreateTcpSocket(TrySocket& tSocket)
{
#ifdef _WINDOWS

	TrySocket sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_ATOM == sock ) {
		return false;
	}

	tSocket = sock;
#endif

	return true;
}

bool Common_CreateUdpSocket(TrySocket& tSocket)
{
#ifdef _WINDOWS
	TrySocket sock = socket(AF_INET, SOCK_DGRAM, 0);
	if ( INVALID_ATOM == sock ) {
		return false;
	}
	tSocket = sock;

#endif

	return true;

}


bool Common_BindSocket(TrySocket& sockHandle, const char* ip, int nPort)
{
#ifdef _WINDOWS
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;	//设置协议类型  AF_INET:V4  AF_INET6:V6
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons((u_short)nPort);
	
	int nResult = bind(sockHandle, (const sockaddr*)&addr, sizeof(addr));
	if (nResult == SOCKET_ERROR ) {
		return false;
	}
#endif
	return true;
}

//当一个应用使用listen系统调用让socket进入LISTEN状态时，它需要为该套接字指定一个backlog。
//backlog通常被描述为连接队列的限制
bool Common_ListenSocket(TrySocket& sockHandle, int nBackLog)
{
#ifdef _WINDOWS
	int nResult  = listen(sockHandle, nBackLog);

	if (nResult == SOCKET_ERROR ) {
		return false;
	}
#endif
	return true;
}

bool Common_CloseSocket(TrySocket sockHandle)
{
#ifdef _WINDOWS
	int result = closesocket(sockHandle);
	if ( result == SOCKET_ERROR ) {
		return false;
	}
#endif
	
	return true;
}

//设置SOCKET 为重复使用地址
bool Common_SetReueaddrSocket(TrySocket& tSocket)
{
	int nFlag = 1;
#ifdef _WINDOWS
	int nRet = setsockopt(tSocket, SOL_SOCKET, SO_REUSEADDR, 
			(const char*)&nFlag, sizeof(nFlag));

	if ( SOCKET_ERROR == nRet ) {
		return false;
	}
#endif
	return true;
}

//设置SOCKET非阻塞模式
bool Common_SetNonBlocking(TrySocket& tSocket)
{
#ifdef _WINDOWS 
	u_long cmd;
	int nRet = ioctlsocket(tSocket, FIONBIO, &cmd);
	if ( nRet == SOCKET_ERROR ) {
		return false;
	}
#endif
	return true;

}



