#ifndef _SLIST_H_
#define _SLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);
SListNode* BuySListNode(SLTDataType x);            //做一个新的结点
void SListPushFront(SListNode** pphead, SLTDataType x);  
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);//查找
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListAllRemove(SListNode** pphead, SLTDataType x);
void SListPrint(SListNode* phead);
void SListReverse1(SListNode** pphead);     //逆序！！！！！！重点
void SListReverse2(SListNode** pphead);     //逆序！！！！！！重点





#endif
