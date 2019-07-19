#ifndef _FUNC_H_
#define _FUNC_H_
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef int SListDate;
////错误代码：
//typedef struct SList
//{
//	SListDate date;
//	SListNode* next;       //这里还不能使用重定义的名字，代码从上到下执行，这时还不知道这个名字，还要写全称struct SList
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