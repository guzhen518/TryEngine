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
	//����һ������
	if ( !Common_CreateTcpSocket(m_Socket) )
	{
		return false;
	}
	
	//���׽������ó�����
	if ( !Common_SetNonBlocking(m_Socket) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//�����׽���Ϊ�ظ�ʹ�õ�ַ
	if ( !Common_SetReueaddrSocket(m_Socket) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//��IP�Ͷ˿�
	if ( !Common_BindSocket(m_Socket, m_szAddr, m_nPort) )
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	//�������
	if ( !Common_ListenSocket(m_Socket, nBackLog))
	{
		Common_CloseSocket(m_Socket);
		return false;
	}

	return true;
}