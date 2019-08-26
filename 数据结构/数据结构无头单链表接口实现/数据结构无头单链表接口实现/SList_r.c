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
	
	for (; phead; phead=phead->_next)
	{
		
		printf("%d->", phead->_data);
	}
	printf("NULL\n");
}
// 在pos的后面进行插入

void SListReverse_r1(SListNode** phead)
{
	SListNode* cur = *phead;
	SListNode* cur_next = *phead;
	SListNode* cur_pre = NULL;

	while (cur)
	{
		cur_next = cur_next->_next;
		cur->_next = cur_pre;
		cur_pre = cur;
		cur = cur_next;
		
	}
	*phead = cur_pre;
}

void SListReverse_r2(SListNode** pphead)
{
	SListNode *pre = *pphead;
	SListNode *tmp = (*pphead)->_next;
	SListNode *next = tmp;
	pre->_next = NULL;
	while (tmp)
	{
		next = tmp->_next;
		tmp->_next = pre;
		pre = tmp;
		tmp = next;
	}
	*pphead = pre;
}

void SListReverse_r3(SListNode** pphead)
{
	SListNode *head = *pphead; //记录头结点，因为一直往前边翻，要记录才能把cur的next值赋值为head，将其翻在前面，再将head更新
	SListNode *pre = *pphead;  //记录一开始的头结点位置，直到他值为空
	SListNode *cur = (*pphead)->_next;
	SListNode *next = cur;
	while (cur)
	{
		next = next->_next;
		cur->_next = head;
		pre->_next = next;
		head = cur;
		cur = next;

	}
	*pphead = head;



}












