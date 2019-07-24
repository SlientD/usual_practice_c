#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
int main()
{
	SeqList* list = (SeqList *)malloc(sizeof(SeqList));  //一定要给结构体指定值，否则他就是野指针。就算在里面为数组开辟空间，也没有办法来给结构体一个确定的空间
	int pos;
	SeqListInit(list, 3);
	SeqListPushBack(list, 5);
	SeqListPushBack(list, 4);
	SeqListPushBack(list, 3);
	SeqListPushBack(list, 2);
	SeqListPushBack(list, 1);
	//pushback
	printf("pushback:");
	SeqListPrint(list);
	//pushfront
	SeqListPushFront(list, 3);
	SeqListPushFront(list, 2);
	SeqListPushFront(list, 2);
	SeqListPushFront(list, 1);
	printf("pushfront:");
	SeqListPrint(list);
	//remove
	printf("remove:");
	SeqListRemove(list, 2);
	SeqListPrint(list);
	//insert
	printf("insert:");
	SeqListInsert(list, 2, 10);
	SeqListPrint(list);
	//bubblesort
	printf("bubblesort;");
	SeqListBubbleSort(list);
	SeqListPrint(list);
	//binaryfind
	printf("binaryfind:");
	pos=SeqListBinaryFind(list, 3);
	printf("%d\n", pos);
	SeqListDestory(list);
	SeqListPrint(list);
	system("pause");
	return 0;
}