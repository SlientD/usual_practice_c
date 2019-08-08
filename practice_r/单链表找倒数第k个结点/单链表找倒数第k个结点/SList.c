#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

void SListInit(SListNode** pphead)
{
	
	*pphead = NULL;

}
SListNode* BuySListNode(SLTDataType x)           
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListPushFront(SListNode** pphead, SLTDataType x)   
{
	SListNode* tmp;
	tmp = BuySListNode(x);
	tmp->_next = *pphead;                              
	*pphead = tmp;                                       
}
void SListEraseAfter(SListNode* pos) 
{
	SListNode* tmp = pos->_next;      
	if (tmp == NULL)                  
	{
		return;
	}
	pos->_next = tmp->_next;
	free(tmp);                         
}

void SListDestory(SListNode** pphead)
{
	while ((*pphead)->_next)
	{
		SListEraseAfter(*pphead);
	}
	free(pphead);
	*pphead = NULL;
}

SLTDataType SListTailFind(SListNode* pphead, int k)
{
	int i = 0;
	SListNode* cur = pphead;
	while (cur)
	{
		i++;
		cur = cur->_next;
	}
	i = i - k + 1;
	cur = pphead;
	while (--i)
	{
		cur = cur->_next;
	}
	return cur->_data;
}

