#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* qu){
	qu->front = NULL;
	qu->rear = NULL;
}
QueueNode* QuBuyNode(QueueDateType x){
	QueueNode* cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}
void QuPush(Queue* qu, QueueDateType x)
{
	QueueNode* cur = QuBuyNode(x);
	if (qu->front == NULL)
	{
		qu->front = cur;
		qu->rear = cur;
		return;
	}

	qu->rear->next = cur;
	qu->rear = cur;
}
void QuPop(Queue* qu)
{
	if (qu->front == NULL)
	{
		return;
	}
	QueueNode* tmp = qu->front;
	
	qu->front = qu->front->next;
	free(tmp);
}
QueueDateType QuFront(Queue* qu)
{
	return qu->front->data;
}

int QuIsEmpty(Queue* qu)
{
	return qu->front == NULL;
}

void QuDestroy(Queue* qu)
{
	QueueNode* tmp = qu->front;
	while (tmp)
	{
		QuPop(qu);
		tmp = tmp->next;
	}
}