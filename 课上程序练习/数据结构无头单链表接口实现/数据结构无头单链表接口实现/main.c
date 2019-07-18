#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

int main()
{
	SListNode* head;     //head还是野指针还未赋值，就是一个存放地址的变量，他的指向有date和next

	SListInit(&head);   //给head一个值，使它指向一个结构体
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head,4);

	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	
	
	printf("原来的：");
	SListPrint(head);
	/*printf("pop后的：");
	SListPopFront(&head);
	SListPrint(head);*/

	/*SListEraseAfter(SListFind(head,3));
	printf("删除3后面节点后的：");
	SListPrint(head);*/

	/*SListInsertAfter(SListFind(head, 3),9);
	printf("3节点后插入9后的：");
	SListPrint(head);*/

	
	//printf("%p\n",SListFind(head, 10));

	/*SListAllRemove(&head, 3);
	printf("删除全部3的：");
	SListPrint(head);*/

	/*SListReverse1(&head);
	printf("逆序1后的：");
	SListPrint(head);*/


	SListReverse2(&head);
	printf("逆序2后的：");
	SListPrint(head);







	system("pause");
	return 0;
}