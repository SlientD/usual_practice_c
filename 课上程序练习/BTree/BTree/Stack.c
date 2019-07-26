#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"



void StackInit(Stack* pq)
{
	pq->top= NULL;
}
StackNode* BuyNode(STDataType x)
{
	StackNode* cur = (StackNode*)malloc(sizeof(StackNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}
void StackPush(Stack* pq, STDataType x)
{
	StackNode * cur = BuyNode(x);
	if (pq->top == NULL)
	{
		pq->top = cur;
		return;
	}
	cur->next = pq->top;
	pq->top = cur;
}
void StackPop(Stack* pq)
{
	StackNode* tmp = pq->top;
	pq->top = pq->top->next;
	//printf("%c", tmp->data->_data);
	free(tmp);
}

STDataType StackFront(Stack* pq){

	return pq->top->data;

}
int StackIsEmpty(Stack* pq)
{
	return pq->top == NULL;
}
void StackDestory(Stack* pq)
{
	StackNode* tmp = pq->top;
	for (; tmp; tmp = tmp->next)
	{
		StackPop(pq);
	}
}