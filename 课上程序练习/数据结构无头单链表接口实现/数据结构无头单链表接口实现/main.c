#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

int main()
{
	SListNode* head;     //head����Ұָ�뻹δ��ֵ������һ����ŵ�ַ�ı���������ָ����date��next

	SListInit(&head);   //��headһ��ֵ��ʹ��ָ��һ���ṹ��
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head,4);

	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	
	
	printf("ԭ���ģ�");
	SListPrint(head);
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


	SListReverse2(&head);
	printf("����2��ģ�");
	SListPrint(head);







	system("pause");
	return 0;
}