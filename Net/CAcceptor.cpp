#include "CAcceptor.h"

TryAcceptor::TryAcceptor(char* szAddr, int nPort, 
	AcceptCallBack pAcceptCb, CloseCallBack pCloseCb, ReceiveCallBack pReceiveCb)
{
	memcpy(m_szAddr, szAddr, 32);

	m_nPort = nPort;
	m_AcceptCallBack = pAcceptCb;
	m_CloseCallBack = pCloseCb;
	m_ReciveCallBack = pReceiveCb;

}

TryAcceptor::~TryAcceptor()
{


}

bool TryAcceptor::Listen(int nBackLog)
{
	//创建一个接受
	if ( !Common_CreateTcpSocket(m_Socket) )
	{
		return false;
	}
	
	//将套接字设置成阻塞
	if ( !Common_SetNonBlocking(m_Socket) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//设置套接字为重复使用地址
	if ( !Common_SetReueaddrSocket(m_Socket) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//绑定IP和端口
	if ( !Common_BindSocket(m_Socket, m_szAddr, m_nPort) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//进入监听
	if ( !Common_ListenSocket(m_Socket, nBackLog))
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	return true;
}