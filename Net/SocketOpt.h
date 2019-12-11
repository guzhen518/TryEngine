#ifndef _LIB_COMMON_SOCKET_H_
#define  _LIB_COMMON_SOCKET_H_



//#include "Macros.h"

#ifdef _WINDOWS
#include <WinSock2.h>
#include <Windows.h>
#include <IPHlpApi.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

#endif // _WINDOWS


#define TYPE_CONNECTOR 0
#define	TYPE_BROADCAST 1
#define TYPE_LISTENER 2

typedef SOCKET  TrySocket;

//初始化网络
bool Common_NetStartUP();

//关闭网络
bool Common_NetStopUP();

//创建TCP连接
bool Common_CreateTcpSocket(TrySocket& tSocket);

//创建UDP连接
bool Common_CreateUdpSocket(TrySocket& tSocket);

//关闭SOCKET连接
bool Common_CloseSocket(TrySocket sockHandle);

//绑定ip & port
bool Common_BindSocket(TrySocket& sockHandle, const char* ip, int nPort);

//监听
bool Common_ListenSocket(TrySocket& sockHandle, int nBackLog);


//设置SOCKET重复使用
bool Common_SetReueaddrSocket(TrySocket& tSocket);

//设置SOCKET非阻塞模式
bool Common_SetNonBlocking(TrySocket& tSocket);



#endif //_LIB_COMMON_SOCKET_H_


