#include "TryLinkList.h"

CLinkList::CLinkList()
{

}

CLinkList::~CLinkList()
{

}

LinkNode* CLinkList::CreateNode(int nData)
{
	LinkNode* pNode = new LinkNode(nData);
	return pNode;
}

bool CLinkList::AddNode(int nData)
{
	LinkNode* pAddNode = CreateNode(nData);
	if (NULL == pAddNode )
	{
		return false;
	}

	LinkNode* pCurrNode = m_pLinkRoot;
	while (!pCurrNode)
	{
		pCurrNode = pCurrNode->pNext;
	}

	if ( NULL == pCurrNode)
	{
		pCurrNode = pAddNode;
	}
	else
	{
		pCurrNode->pNext = pAddNode;
	}
}

bool CLinkList::RemoveNode(int nKey)
{




}

LinkNode* CLinkList::ReverseNode(LinkNode* pHead)
{
	if (NULL == pHead || NULL == pHead->pNext )
	{
		return NULL;
	}

	LinkNode* pPre = NULL;

	while (NULL != pHead )
	{
		LinkNode* pNext = pHead->pNext;
		pHead->pNext = pPre;
		pPre = pHead;
		pHead = pNext;
	}

	return pPre;

}

bool CLinkList::HasCircle(LinkNode* pHead, LinkNode*& pCirNode)
{
	if (NULL == pHead )
	{
		return false;
	}

	LinkNode* pSlow = NULL;
	LinkNode* pFast = NULL;

	pSlow = pFast = pHead;

	while (NULL != pFast && NULL != pFast->pNext )
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;

		if (pSlow == pFast )
		{
			pCirNode = pSlow;
			return true;
		}
	}

	return false;

}

LinkNode* CLinkList::GetNodeByK(int k)
{
	if (k <= 0 )
	{
		return NULL;
	}

	LinkNode* pSlow = NULL;
	LinkNode* pFast = NULL;

	pSlow = pFast = m_pLinkRoot;
	
	int nLoop = k;
	for (; nLoop > 0; --nLoop)
	{
		pFast = pFast->pNext;
	}

	if (nLoop > 0)
	{
		return NULL;
	}

	while (NULL != pFast )
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}

	return pSlow;
}

