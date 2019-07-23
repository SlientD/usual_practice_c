#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


void QueueInit(Queue* pq)
{
	pq->front = pq->rear=pq->data;          //ʵ���ϻ����������ڽ��в���
	pq->size = 0;
	

}
void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;          //�ص���ʼ״̬
	pq->size = 0;
}
void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size+1 == QueueMax){            //	if (pq->rear+1==pq->front||(pq->rear+1-QueueMax==pq->front&&pq->front==pq->data))...һ�����������������һ������ β�����һ���յĿռ��˶���ͷ�ڵ�һ����Ҳ������ 
		return;
	}

	*(pq->rear) = x;
	pq->rear++;
	if (pq->rear - pq->data == QueueMax)       //���ų��ӣ�frontҲҪ��
	{
		pq->rear = pq->data;                   //��ͷ�ˣ��ص�������¿�ʼ���롣������������������һ���Ѿ��жϳ�����
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;                               
	if (pq->rear - pq->data == QueueMax)      //�����һ��Ԫ������ʱ�����һ���ռ�Ҳ��ȥ�ˣ�front�����һ��Ԫ�ص���һ���ռ��ˣ�������Ƕȹ�Ԫ�صĸ���
	{
		pq->rear = pq->data;                   //front��ͷ�ˣ���˻ص�������¿�ʼ
	}
	pq->size--;
}
QuDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return (QuDataType)-1;
	}
	return *pq->front;
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return 0;
	}
	if (pq->rear == pq->data)                         //rearָ�����һ��Ԫ�ص���һ���ռ䣬����Ѿ����ȥ�ˣ���Ҫ���һ��Ԫ��
	{
		return pq->data[QueueMax - 1];

	}
	else
		return *(pq->rear--);
}