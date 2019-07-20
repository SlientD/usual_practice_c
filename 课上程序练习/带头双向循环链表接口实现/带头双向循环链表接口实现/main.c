#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
int main()
{
	List list;
	List list1;
	ListInit(&list);
	ListInit(&list1);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPushBack(&list, 3);
	ListPushBack(&list, 2);
	ListPushFront(&list, 6);
	ListPushBack(&list1, 5);
	ListPushBack(&list1, 4);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 2);
	ListPushFront(&list1, 7);
	ListPrint(&list);
	ListPrint(&list1);
	ListMerge(&list, &list1);
	/*ListRemove(&list,3);
	ListPrint(&list);*/
	/*ListRemoveDuplicates(&list);
	ListPrint(&list);
	ListNodeChange(ListFind(&list, 1), ListFind(&list, 6));*/
	ListPrint(&list);

	system("pause");
	return 0;
}