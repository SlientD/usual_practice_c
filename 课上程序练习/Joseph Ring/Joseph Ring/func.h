#ifndef _FUNC_H_
#define _FUNC_H_
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int SListDate;
////������룺
//typedef struct SList
//{
//	SListDate date;
//	SListNode* next;       //���ﻹ����ʹ���ض�������֣�������ϵ���ִ�У���ʱ����֪��������֣���Ҫдȫ��struct SList
//}SListNode;
typedef struct SList
{
	SListDate date;
	struct SList* next;
}SListNode;

void SListInit(SListNode** pphead);
SListNode* SListNodeCreate(SListDate x);

void SListPush(SListNode** pphead, SListDate x);
void SListPop(SListNode** pphead);
void SListEraseAfter(SListNode* phead);


#endif