#ifndef	_NET_COMMON_ACCEPTOR_H_
#define _NET_COMMON_ACCEPTOR_H_

#include "SocketOpt.h"


class CAcceptor
{
public:
	CAcceptor();
	~CAcceptor()
public:
	void Listen();
private:
	TrySocket m_nAcceptSocket;
	 


};


#endif
