#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct SListNode{
	DataType data;
	struct SListNode* next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;


void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(DataType x);
void SListPushFront(SList* plist, DataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, DataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, DataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, DataType x);
void SListPrint(SList* plist);







#endif