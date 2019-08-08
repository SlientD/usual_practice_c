#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#define ARR(a)  (sizeof(a)/sizeof(a[0]))

int main(){

	Heap hp;
	HPDataType a[] = { 1, 6, 3, 7, 9, 8 };
	HeapInit(&hp,a, ARR(a));
	printf("1.init\n");
	HeapPrint(&hp);
    HeapPush(&hp, 10);
	printf("\n2.push\n");
	HeapPrint(&hp);

	HeapPop(&hp);
	printf("\n3.pop\n");
	HeapPrint(&hp);
	printf("\n4.sort\n");
	HeapSort(&hp);
	HeapPrint(&hp);


	system("pause");
	return 0;
}