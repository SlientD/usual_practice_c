#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

void SListInit(SListNode** pphead)
{
	*pphead = NULL;

}
SListNode* SListNodeCreate(SListDate x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->date = x;
	tmp->next = NULL;
	return tmp;
}
void SListPush(SListNode** pphead, SListDate x)
{
	SListNode* tmp = SListNodeCreate(x);
	tmp->next = *pphead;
	*pphead = tmp;
}
void SListPop(SListNode** pphead)
{
	SListNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);

}
void SListEraseAfter(SListNode* phead)
{
	SListNode* tmp = phead->next;
	phead->next = phead->next->next;
	free(tmp);
}