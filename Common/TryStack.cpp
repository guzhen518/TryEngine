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

	return true;
}

bool CLinkList::RemoveNode(int nKey)
{
	if (NULL == m_pLinkRoot )
	{
		return false;
	}

	LinkNode* pPreNode = NULL;
	LinkNode* pRemoveNode = m_pLinkRoot;
	while (NULL != pRemoveNode && pRemoveNode->nData == nKey )
	{
		pPreNode = pRemoveNode;
		pRemoveNode = pRemoveNode->pNext;
	}

	if (pRemoveNode->nData != nKey )
	{
		return false;
	}

	LinkNode* pNext = pRemoveNode->pNext;
	delete pRemoveNode;
	pPreNode->pNext = pNext;

	return true;

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
		LinkNode* pNext	= pHead->pNext;
		pHead->pNext	= pPre;
		pPre	= pHead;
		pHead	= pNext;
	}

	return pPre;

}


//此题的解决思路和第3题「求链表的倒数第 k 个节点」很相似。
//可以先求链表的长度，然后计算出中间节点所在链表顺序的位置。
//但是如果要求只能扫描一遍链表，如何解决呢？最高效的解法和第3题一样，
//通过两个指针来完成。用两个指针从链表头节点开始，一个指针每次向后移动两步，
//一个每次移动一步，直到快指针移到到尾节点，那么慢指针即是所求。
LinkNode* CLinkList::GetMiddleNode()
{
	if (NULL == m_pLinkRoot )
	{
		return NULL;
	}

	LinkNode* pSlow = NULL;
	LinkNode* pFast = NULL;

	pSlow = pFast = m_pLinkRoot;


	while (NULL != pFast && NULL != pFast->pNext )
	{

		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}

	return pSlow;


}


//通过两个指针，分别从链表的头节点出发，一个每次向后移动一步，另一个移动两步，
//两个指针移动速度不一样，如果存在环，那么两个指针一定会在环里相遇。
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

// 由上题可知，按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和 p1 重合，确定了单向链表有环路了。
//接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当 p1 和 p2 再次相遇的时候，就是环路的入口了。
LinkNode* CLinkList::FindLoopNode()
{
	if (NULL == m_pLinkRoot )
	{
		return NULL;
	}

	LinkNode* pSlow = NULL;
	LinkNode* pFast = NULL;

	pFast = pSlow = m_pLinkRoot;

	while (NULL != pFast && NULL != pFast->pNext )
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;
		if (pSlow == pFast )
		{
			break;
		}
	}

	if (pSlow != pFast )
	{
		return NULL;
	}

	pFast = m_pLinkRoot;

	while (pFast != pSlow )
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}

	return pFast;

}

LinkNode* CLinkList::ReverseNodeT(LinkNode* pHead)
{
	if (NULL == pHead )
	{
		return NULL;
	}

	LinkNode* pNewHead = NULL;
	while (NULL != pHead )
	{
		LinkNode* pNextNode = pHead->pNext;
		pHead->pNext = pNewHead;
		pNewHead = pHead;
		pHead = pNextNode;
	}

	return pNewHead;

}
