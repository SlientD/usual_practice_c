#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


void QueueInit(Queue* pq)
{
	pq->front = pq->rear=pq->data;          //实际上还是在数组内进行操作
	pq->size = 0;
	

}
void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;          //回到初始状态
	pq->size = 0;
}
void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size+1 == QueueMax){            //	if (pq->rear+1==pq->front||(pq->rear+1-QueueMax==pq->front&&pq->front==pq->data))...一样的两种情况，相差等一，或者 尾到最后一个空的空间了而且头在第一个，也是满的 
		return;
	}

	*(pq->rear) = x;
	pq->rear++;
	if (pq->rear - pq->data == QueueMax)       //随着出队，front也要变
	{
		pq->rear = pq->data;                   //到头了，回到起点重新开始插入。满不满结束不结束上一步已经判断出来了
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
	if (pq->rear - pq->data == QueueMax)      //当最后一个元素跳过时，最后一个空间也过去了，front到最后一个元素的下一个空间了，相减就是度过元素的个数
	{
		pq->rear = pq->data;                   //front到头了，因此回到起点重新开始
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
	if (pq->rear == pq->data)                         //rear指向最后一个元素的下一个空间，如果已经跨过去了，就要最后一个元素
	{
		return pq->data[QueueMax - 1];

	}
	else
		return *(pq->rear--);
}