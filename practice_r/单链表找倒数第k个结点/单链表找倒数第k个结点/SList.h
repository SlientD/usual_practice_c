#ifndef _SLIST_H_
#define _SLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

void SListInit(SListNode** pphead);
SListNode* BuySListNode(SLTDataType x);            
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListDestory(SListNode** pphead);
SLTDataType SListTailFind(SListNode* pphead, int x);





#endif
