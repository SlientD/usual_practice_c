#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

#define QueueMax 4
typedef int QuDataType;
typedef struct Queue
{
	QuDataType data[QueueMax];            //使用结构体，基本都使用指针，因为结构体占空间太大，QueueMax很大时，栈会崩掉
	QuDataType *front;                    //定长的
	QuDataType *rear;
	size_t size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);
QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);




#endif