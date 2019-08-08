#ifndef _STACK_H_
#define _STACK_H_

#include "BTree.h"


typedef BTNode* STDataType;
typedef struct StackNode{
	STDataType  data;
	struct StackNode* next;
}StackNode;


typedef struct Stack
{

	StackNode* top;    // Õ»¶¥
	int size;
}Stack;

void StackInit(Stack* pq);
void StackPush(Stack* pq, STDataType x);
void StackPop(Stack* pq);
STDataType StackFront(Stack* pq);
int StackIsEmpty(Stack* pq);

void StackDestory(Stack* pq);






#endif