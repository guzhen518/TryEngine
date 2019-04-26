#ifndef		_LIB_COMMON_LINK_LIST_H_
#define		_LIB_COMMON_LINK_LIST_H_

#include "Macros.h"


struct LinkNode 
{
	LinkNode()
	{
		nData = 0;
	}

	LinkNode(int value)
	{
		nData = nData;
		pNext = NULL;
	}

	LinkNode* pNext;
	int nData;
};

class CLinkList
{
public:
	CLinkList();
	~CLinkList();

public:
	LinkNode* CreateNode(int nData);
	bool AddNode(int nData);
	bool RemoveNode(int nKey);
	bool RemoveNode(LinkNode* pRemoveNode);
	LinkNode* ReverseNode(LinkNode* pNode);
	LinkNode* GetNodeByK(int k);
	bool	HasCircle(LinkNode* pHead, LinkNode*& pCirNode);
	LinkNode* FindLoopNode();

	LinkNode* GetMiddleNode();
private:
	LinkNode* m_pLinkRoot;

};


#endif //_LIB_COMMON_LINK_LIST_H_
