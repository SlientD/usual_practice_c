#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "BTree.h"

typedef BTreeNode* QueueDateType; 
typedef struct QueueNode{
	QueueDateType data;
	struct QueueNode* next;
}QueueNode;
typedef struct Queue{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void QueueInit(Queue* qu);
QueueNode* QuBuyNode(QueueDateType x);
void QuPush(Queue* qu, QueueDateType x);
void QuPop(Queue* qu);
QueueDateType QuFront(Queue* qu);
int QuIsEmpty(Queue* qu);
void QuDestroy(Queue* qu);



#endif