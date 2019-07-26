#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


void QueueInit(Queue* pq)
{
	pq->front = pq->rear = NULL;
}

void QueuePush(Queue* pq, QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	if (pq->front == NULL)
	{
		pq->front = pq->rear = cur;
		return;
	}
	pq->rear->next= cur;
	pq->rear = cur;
}

void QueuePop (Queue* pq)
{
	QueueNode * tmp ;
	tmp = pq->front;
	pq->front = tmp->next;                             //最后是会等于null的 
	printf("%c", tmp->data->_data);
	free(tmp);

}

int QueueIsEmpty(Queue* pq)
{
	return pq->front == NULL;
}
void QueueDestory(Queue* pq)
{
	pq->front = NULL;
}