#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

typedef BTNode* QuDataType;
typedef struct QueueNode{
	QuDataType data;
	struct QueueNode * next;
}QueueNode;
typedef struct Queue             //定义这个结构体，只存放队列的头和尾，在队列的改变中，不停的改变头和尾，在 逻辑顺序上就可以连成一个队列
{
	QueueNode *front;            //front和rear也是个NODE存放他们就是象征的表示一个队列的范围   
	QueueNode *rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);
int QueueIsEmpty(Queue* pq);



#endif