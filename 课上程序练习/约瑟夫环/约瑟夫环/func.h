#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _FUNC_H_
#define _FUNC_H_
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int SListDate;
typedef struct SList
{
	SListDate date;
	SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
SListNode* SListNodeCreate(SListDate x);

void SListPush(SListNode** pphead, SListDate x);
void SListPop(SListNode** pphead);
void SListEraseAfter(SListNode* phead);






#endif