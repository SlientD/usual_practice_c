#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SListInit(SList* plist)
{
	plist->_head = (SListNode*)malloc(sizeof(SListNode));
	plist->_head->next = NULL;
}

SListNode* BuySListNode(DataType x)
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}
void SListPushFront(SList* plist, DataType x)
{
	SListNode* cur = BuySListNode(x);
	cur->next = plist->_head->next;
	plist->_head->next = cur;
}
void SListPopFront(SList* plist){
	SListNode* tmp ;
	tmp = plist->_head->next;
	plist->_head->next = tmp->next;
	free(tmp);
}
void SListPrint(SList* plist)
{
	SListNode* cur;
	for (cur = plist->_head->next; cur; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("null\n");

}
SListNode* SListFind(SList* plist, DataType x)
{
	SListNode* cur;
	for (cur = plist->_head->next; cur; cur = cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;

}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, DataType x)
{
	SListNode* cur = BuySListNode(x); 
	cur->next=pos->next;
	pos->next = cur;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp;
	tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}

void SListAllRemove(SList* plist, DataType x)
{
	SListNode* cur;
	for (cur = plist->_head->next; cur->next; cur = cur->next)
	{
		if (cur->next->data == x)
		{
			SListEraseAfter(cur);
		}
	}
}
void SListDestory(SList* plist)
{
	SListNode* cur,*tmp;
	for (tmp = plist->_head->next; tmp; tmp = cur)
	{
		cur = tmp->next;
		free(tmp);
	}
	free(plist->_head);
}