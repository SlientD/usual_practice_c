#ifndef _STACK_H_
#define  _STACK_H_

#include "BTree.h"
typedef BTreeNode * STDataType;

typedef struct Stack {
	STDataType* arr;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t cap;   // 容量空间的大小
}Stack;

void StackInite(Stack* st, int cap);
void StackCheckCap(Stack* st);
void StackPush(Stack* st, STDataType x);
void StackPop(Stack* st);
STDataType StackFront(Stack* st);
int StackIsEmpty(Stack* st);





#endif