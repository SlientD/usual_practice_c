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
typedef struct Queue             //��������ṹ�壬ֻ��Ŷ��е�ͷ��β���ڶ��еĸı��У���ͣ�ĸı�ͷ��β���� �߼�˳���ϾͿ�������һ������
{
	QueueNode *front;            //front��rearҲ�Ǹ�NODE������Ǿ��������ı�ʾһ�����еķ�Χ   
	QueueNode *rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);
int QueueIsEmpty(Queue* pq);



#endif