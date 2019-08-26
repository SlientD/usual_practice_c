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
	
	for (; phead; phead=phead->_next)
	{
		
		printf("%d->", phead->_data);
	}
	printf("NULL\n");
}
// ��pos�ĺ�����в���

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
	SListNode *head = *pphead; //��¼ͷ��㣬��Ϊһֱ��ǰ�߷���Ҫ��¼���ܰ�cur��nextֵ��ֵΪhead�����䷭��ǰ�棬�ٽ�head����
	SListNode *pre = *pphead;  //��¼һ��ʼ��ͷ���λ�ã�ֱ����ֵΪ��
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












