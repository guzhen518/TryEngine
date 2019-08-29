#ifndef _LIB_COMMON_SOCKET_H_
#define  _LIB_COMMON_SOCKET_H_


#include <WinSock2.h>
#include <Windows.h>
#include <IPHlpApi.h>
//#include "Macros.h"


#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

typedef SOCKET  TrySocket;

//初始化网络
bool Common_NetStartUP();

//关闭网络
bool Common_NetStopUP();

//创建TCP连接
bool Common_CreateTcpSocket(TrySocket* pTrySocket);

//创建UDP连接
bool Common_CreateUdpSocket(TrySocket* pTrySocket);

//关闭SOCKET连接
bool Common_CloseSocket(TrySocket sockHandle);

//绑定ip & port
bool Common_BindSocket(TrySocket sockHandle, const char* ip, int nPort);



#endif //_LIB_COMMON_SOCKET_H_

