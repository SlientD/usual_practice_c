#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"
void SListInit_r(SListNode* phead)
{
	phead->_data = NULL;
	phead->_next = NULL;
}

SListNode* BuySListNode_r(SLTDataType x)           //做一个新的结点
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListPushFront_r(SListNode* pphead, SLTDataType x)   //头插，头节点的地址要换 ，所以要传存头节点地址变量的地址，才能改变头节点地址的值 
{
	SListNode* tmp;
	tmp = BuySListNode_r(x);
	tmp->_next = pphead;                               
	pphead->_data = tmp->_data;                            //改变了pphead的指向的值    ，并没有改变他的内容 
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
// 在pos的后面进行插入













