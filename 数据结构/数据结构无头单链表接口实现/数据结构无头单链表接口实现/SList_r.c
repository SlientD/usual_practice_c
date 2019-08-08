#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"
void SListInit_r(SListNode** phead)
{
	*phead = NULL;
}

SListNode* BuySListNode_r(SLTDataType x)           //做一个新的结点
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListPushFront_r(SListNode** pphead, SLTDataType x)   //头插，头节点的地址要换 ，所以要传存头节点地址变量的地址，才能改变头节点地址的值 
{
	SListNode* tmp;
	tmp = BuySListNode_r(x);
	tmp->_next = *pphead;                               
	*pphead = tmp;
}



void SListPrint_r(SListNode* phead)
{
	
	for (; phead._next; phead=*(phead._next))
	{
		
		printf("%d->", phead._data);
	}
	printf("NULL\n");
}
// 在pos的后面进行插入

void SListReverse_r(SListNode* phead)
{
	SListNode* cur = phead;
	SListNode* cur_next = phead;
	SListNode* cur_pre = NULL;

	while (cur)
	{
		cur_next = cur_next->_next;
		cur->_next = cur_pre;
		cur_pre = cur;
		cur = cur_next;
		
	}
	phead->_data = cur_pre->_data;
	phead->_next = cur_pre->_next;
}












