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


//����Ľ��˼·�͵�3�⡸������ĵ����� k ���ڵ㡹�����ơ�
//������������ĳ��ȣ�Ȼ�������м�ڵ���������˳���λ�á�
//�������Ҫ��ֻ��ɨ��һ��������ν���أ����Ч�Ľⷨ�͵�3��һ����
//ͨ������ָ������ɡ�������ָ�������ͷ�ڵ㿪ʼ��һ��ָ��ÿ������ƶ�������
//һ��ÿ���ƶ�һ����ֱ����ָ���Ƶ���β�ڵ㣬��ô��ָ�뼴������
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


//ͨ������ָ�룬�ֱ�������ͷ�ڵ������һ��ÿ������ƶ�һ������һ���ƶ�������
//����ָ���ƶ��ٶȲ�һ����������ڻ�����ô����ָ��һ�����ڻ���������
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

// �������֪������ p2 ÿ��������p1 ÿ��һ���ķ�ʽ�ߣ����� p2 �� p1 �غϣ�ȷ���˵��������л�·�ˡ�
//����������p2�ص������ͷ���������ߣ�ÿ�β���������2�ˣ�������1����ô�� p1 �� p2 �ٴ�������ʱ�򣬾��ǻ�·������ˡ�
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
