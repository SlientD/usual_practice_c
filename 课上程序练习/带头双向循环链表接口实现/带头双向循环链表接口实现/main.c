#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 5);
	ListPushBack(&list, 5);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPushBack(&list, 3);
	ListPushBack(&list, 2);
	ListPushBack(&list, 1);
	ListPushBack(&list, 1);
	ListPushFront(&list, 6);
	ListPushFront(&list, 6);
	ListPushFront(&list, 6);
	ListPushFront(&list, 6);
	ListPrint(&list);
	/*ListRemove(&list,3);
	ListPrint(&list);*/
	ListRemoveDuplicates(&list);
	ListPrint(&list);
	ListNodeChange(ListFind(&list, 1), ListFind(&list, 6));
	ListPrint(&list);

	system("pause");
	return 0;
}