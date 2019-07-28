#ifndef _STACK_H_
#define  _STACK_H_

#include "BTree.h"
typedef BTreeNode * STDataType;

typedef struct Stack {
	STDataType* arr;  // ָ��̬���ٵ�����
	size_t size;       // ��Ч���ݸ���
	size_t cap;   // �����ռ�Ĵ�С
}Stack;

void StackInite(Stack* st, int cap);
void StackCheckCap(Stack* st);
void StackPush(Stack* st, STDataType x);
void StackPop(Stack* st);
STDataType StackFront(Stack* st);
int StackIsEmpty(Stack* st);





#endif