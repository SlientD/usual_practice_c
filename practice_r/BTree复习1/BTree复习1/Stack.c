#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void StackInite(Stack* st, int cap)
{
	st->arr = (STDataType*)malloc(cap*sizeof(STDataType));
	st->size = 0;
	st->cap = cap;
}

void StackCheckCap(Stack* st)
{
	if (st->size + 1 > st->cap)
	{
		st->cap = 2 * st->cap;
		st->arr = (STDataType*)realloc(st->arr, st->cap*sizeof(STDataType));
	}
}
void StackPush(Stack* st, STDataType x)
{
	StackCheckCap(st);
	
	st->arr[st->size] = x;
	(st->size)++;                      //使栈顶总指向下一个空间
}

void StackPop(Stack* st)
{
	if (st->size > 0){
		st->size--;
	}
}

STDataType StackFront(Stack* st){
	if (st->size > 0){
		return st->arr[st->size - 1];
	}
	else{
		return NULL;
	}
}

int StackIsEmpty(Stack* st){
	return st->size == 0;
 }

void StackDestroy(Stack* st){
	free(st->arr);
	st->cap = 0;
	st->size = 0;
}