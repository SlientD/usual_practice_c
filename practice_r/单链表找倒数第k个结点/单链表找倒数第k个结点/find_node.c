#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"




int main()
{
	SListNode* node;
	SLTDataType x;
	SListInit(&node);
	SListPushFront(&node, 5);
	SListPushFront(&node, 4);
	SListPushFront(&node, 3);
	SListPushFront(&node, 2);
	SListPushFront(&node, 1);
	x=SListTailFind(node,5);
	printf("%d", x);
	system("pause");
	return 0;
}

