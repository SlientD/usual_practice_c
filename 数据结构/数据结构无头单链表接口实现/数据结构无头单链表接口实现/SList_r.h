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

void SListInit_r(SListNode* pphead);
SListNode* BuySListNode_r(SLTDataType x);            //��һ���µĽ��
void SListPushFront_r(SListNode* pphead, SLTDataType x);

void SListPrint_r(SListNode phead);





#endif
