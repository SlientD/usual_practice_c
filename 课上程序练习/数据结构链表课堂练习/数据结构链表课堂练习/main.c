#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"


int main()
{
	SeqList list;
	SeqListInit(&list,100);
	//SeqListDestory(&list);
	//CheckCapacity(&list);
	SeqListPushBack(&list, 5);
	SeqListPushBack(&list, 6);
	SeqListPushBack(&list, 7);
	SeqListPushBack(&list, 7);
	SeqListPushBack(&list, 8);
	SeqListPushBack(&list, 9);
	
	SeqListPushFront(&list,4);
	SeqListPushFront(&list,3);
	SeqListPushFront(&list,2);
	SeqListPushFront(&list,1);
	/*SeqListPopFront(&list);
	SeqListPopBack(&list);
    SeqListFind(&list, 5);
	SeqListInsert(&list, 4, 9);
	SeqListErase(&list, 5);
	SeqListRemove(&list, 0);
	SeqListModify(&list, 3, 10);*/
	SeqListPrint(&list);
	SeqListBubbleSort(&list);
	SeqListPrint(&list);
	SeqListAllRemove(&list, 9);
	SeqListPrint(&list);
	printf("%d\n", SeqListBinaryFind(&list, 5));
	system("pause");
	return 0;
}