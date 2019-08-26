#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"

#if 0
int main()
{
	SListNode* head;     //head还是野指针还未赋值，就是一个存放地址的变量，他的指向有date和next
	SListNode* head1;
	SListNode* start;
	SListNode* tmp;
	SListInit(&head);   //给head一个值，使它指向一个结构体
	SListPushFront(&head, 2);
	tmp = head;
	SListPushFront(&head, 3);
	SListPushFront(&head,4);
	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	SListPushFront(&head, 7);
	start = head;
	SListPushFront(&head, 8);
	//tmp->_next = start;
	if (exitCycle(head))
	{

		printf("%d\n", detectCycle(head)->_data);
	}
	else{
		printf("null\n");
	}
#endif
	int main()
	{
		SListNode* head;     //head还是野指针还未赋值，就是一个存放地址的变量，他的指向有date和next
		//SListNode* head1;
		SListInit_r(&head);

		SListPushFront_r(&head, 2);
		
		SListPushFront_r(&head, 3);
		SListPushFront_r(&head, 4);
		SListPushFront_r(&head, 5);
		SListPushFront_r(&head, 6);
		SListPushFront_r(&head, 7);
		SListPushFront_r(&head, 8);
		SListPrint_r(head);
		SListReverse_r3(&head);
		SListPrint_r(head);
		//tmp->_next = start;
		
	/*SListInit(&head1);
	SListPushFront(&head1, 3);*/
	/*SListPushFront(&head1, 4);
	SListPushFront(&head1, 5);
	SListPushFront(&head1, 6);*/
	//head1->_next = head;
	
	/*printf("原来的head：");
	SListPrint(head);*/
	/*printf("原来的head1：");
	SListPrint(head1);
	if (SListFindCommenNode(head, head1))
	{
		printf("相同节点在哪？：%d\n", SListFindCommenNode(head, head1)->_data);
	}
	else{
		printf("相同节点在哪？null");
	}*/


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


	/*SListReverse2(&head);
	printf("逆序2后的：");
	SListPrint(head);*/







	system("pause");
	return 0;
}