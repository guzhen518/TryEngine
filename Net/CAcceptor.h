#ifndef	_NET_COMMON_ACCEPTOR_H_
#define _NET_COMMON_ACCEPTOR_H_

#include "SocketOpt.h"

typedef void (*AcceptCallBack)(void* pContext, int nListenId, const char* szAddr, int nPort);
typedef void (*CloseCallBack)(void* pContext, int nConnectId, const char* szAddr, int nPort);
typedef void(*ReceiveCallBack)(void* pContext, int nConnectId, const void* pData, size_t nLen);


class TryAcceptor
{
public:
	TryAcceptor(char* szAddr, int nPort, AcceptCallBack pAcceptCallBack, CloseCallBack pCloseCallBack, ReceiveCallBack pReceiveCallBack);
	~TryAcceptor();
public:
	bool Listen(int nBackLog);
private:
	char m_szAddr[32];
	int m_nPort;
	int m_nInBuffLen;
	int m_nOutBuffLen;
	int m_nOutBuffMax;
	TrySocket m_Socket;
	AcceptCallBack m_AcceptCallBack;
	CloseCallBack m_CloseCallBack;
	ReceiveCallBack m_ReciveCallBack;
};


#endif
