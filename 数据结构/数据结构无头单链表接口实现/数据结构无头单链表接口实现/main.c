#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist_r.h"

#if 0
int main()
{
	SListNode* head;     //head����Ұָ�뻹δ��ֵ������һ����ŵ�ַ�ı���������ָ����date��next
	SListNode* head1;
	SListNode* start;
	SListNode* tmp;
	SListInit(&head);   //��headһ��ֵ��ʹ��ָ��һ���ṹ��
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
		SListNode* head;     //head����Ұָ�뻹δ��ֵ������һ����ŵ�ַ�ı���������ָ����date��next
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
	
	/*printf("ԭ����head��");
	SListPrint(head);*/
	/*printf("ԭ����head1��");
	SListPrint(head1);
	if (SListFindCommenNode(head, head1))
	{
		printf("��ͬ�ڵ����ģ���%d\n", SListFindCommenNode(head, head1)->_data);
	}
	else{
		printf("��ͬ�ڵ����ģ�null");
	}*/


	/*printf("pop��ģ�");
	SListPopFront(&head);
	SListPrint(head);*/

	/*SListEraseAfter(SListFind(head,3));
	printf("ɾ��3����ڵ��ģ�");
	SListPrint(head);*/

	/*SListInsertAfter(SListFind(head, 3),9);
	printf("3�ڵ�����9��ģ�");
	SListPrint(head);*/

	
	//printf("%p\n",SListFind(head, 10));

	/*SListAllRemove(&head, 3);
	printf("ɾ��ȫ��3�ģ�");
	SListPrint(head);*/

	/*SListReverse1(&head);
	printf("����1��ģ�");
	SListPrint(head);*/


	/*SListReverse2(&head);
	printf("����2��ģ�");
	SListPrint(head);*/







	system("pause");
	return 0;
}