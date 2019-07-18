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
SListNode* BuySListNode(SLTDataType x);            //��һ���µĽ��
void SListPushFront(SListNode** pphead, SLTDataType x);  
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);//����
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);
void SListAllRemove(SListNode** pphead, SLTDataType x);
void SListPrint(SListNode* phead);
void SListReverse1(SListNode** pphead);     //���򣡣����������ص�
void SListReverse2(SListNode** pphead);     //���򣡣����������ص�





#endif
