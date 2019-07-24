#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef int SeqDataType;
typedef struct SeqList{
	SeqDataType* arr;
	size_t size;
	size_t capacity;
}SeqList;


void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl); 
void SeqListPushBack(SeqList* psl, SeqDataType x);
void SeqListPopBack(SeqList* psl); 
void SeqListPushFront(SeqList* psl, SeqDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SeqDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SeqDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SeqDataType x);
void SeqListModify(SeqList* psl, size_t pos, SeqDataType x);
void SeqListPrint(SeqList* psl);

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SeqDataType x);





#endif