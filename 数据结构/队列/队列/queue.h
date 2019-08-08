#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

#define QueueMax 4
typedef int QuDataType;
typedef struct Queue
{
	QuDataType data[QueueMax];            //ʹ�ýṹ�壬������ʹ��ָ�룬��Ϊ�ṹ��ռ�ռ�̫��QueueMax�ܴ�ʱ��ջ�����
	QuDataType *front;                    //������
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