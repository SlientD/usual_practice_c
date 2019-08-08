#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"
void SListInit_r(SListNode** phead)
{
	*phead = NULL;
}

SListNode* BuySListNode_r(SLTDataType x)           //��һ���µĽ��
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListPushFront_r(SListNode** pphead, SLTDataType x)   //ͷ�壬ͷ�ڵ�ĵ�ַҪ�� ������Ҫ����ͷ�ڵ��ַ�����ĵ�ַ�����ܸı�ͷ�ڵ��ַ��ֵ 
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
// ��pos�ĺ�����в���

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












