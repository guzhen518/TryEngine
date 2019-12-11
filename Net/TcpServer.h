#ifndef _TRY_TCP_SERVER_H_
#define  _TRY_TCP_SERVER_H_

#include "EventLoop.h"

typedef void(*AcceptCallBack)(void* pContext, int nListenId, const char* szAddr, int nPort);
typedef void(*CloseCallBack)(void* pContext, int nConnectId, const char* szAddr, int nPort);
typedef void(*ReceiveCallBack)(void* pContext, int nConnectId, const void* pData, size_t nLen);

class TryTcpServer
{
public:
	TryTcpServer();
	~TryTcpServer();

public:
	bool Start();
	bool Run();
	bool Stop();
public:
	bool CreateListen(const char* szAddr, int nPort, AcceptCallBack acceptCB, CloseCallBack closeCB, ReceiveCallBack receiveCB);
	bool CreateConnect();


};



#endif	//_TRY_TCP_SERVER_H_
