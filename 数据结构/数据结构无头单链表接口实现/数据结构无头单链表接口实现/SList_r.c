#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"
void SListInit_r(SListNode* phead)
{
	phead->_data = NULL;
	phead->_next = NULL;
}

SListNode* BuySListNode_r(SLTDataType x)           //��һ���µĽ��
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListPushFront_r(SListNode* pphead, SLTDataType x)   //ͷ�壬ͷ�ڵ�ĵ�ַҪ�� ������Ҫ����ͷ�ڵ��ַ�����ĵ�ַ�����ܸı�ͷ�ڵ��ַ��ֵ 
{
	SListNode* tmp;
	tmp = BuySListNode_r(x);
	tmp->_next = pphead;                               
	pphead->_data = tmp->_data;                            //�ı���pphead��ָ���ֵ    ����û�иı��������� 
	pphead->_next = tmp->_next;
}



void SListPrint_r(SListNode phead)
{
	
	for (; phead._next; phead=*(phead._next))
	{
		
		printf("%d->", phead._data);
	}
	printf("NULL\n");
}
// ��pos�ĺ�����в���













