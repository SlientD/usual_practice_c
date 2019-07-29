#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#define ARRSIZE(a)  (sizeof(a)/sizeof(a[0]))

#include "Heap.h"
#include <string.h>
#include <stdio.h>

#if 1
void swap(HPDataType *a, HPDataType *b)  //最后一步若是自己和自己交换，把自己和自己异或，同时又修改了自己的对应地址的空间，赋值*a的同时又把*b给改掉了，所以将sort的条件改为大于一，只剩一个节点的时候不交换
{
	
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
#else
void swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif
void DownAdjust(Heap *hp, int n)    //n 是要调整结点所在数组中的下标
{
	int cur = n;
	while (cur*2+1<hp->size)     //如果一个堆没有左节点，那他一定是叶子，直接跳出
	{
		if (hp->data[cur] < hp->data[cur * 2 + 1])       //大根堆中，cur比他的左节点还小，执行交换
		{
			if (cur * 2 + 2>=hp->size || hp->data[2 * cur + 2] <= hp->data[cur * 2 + 1])       //如果右孩子不存在或者左孩子大于右孩子
			{
				swap(&hp->data[cur], &hp->data[cur * 2 + 1]);     //和左孩子换
				cur = cur * 2 + 1;                       //换位
			}
			else{                                        //如果右孩子大于左孩子，和右孩子交换
				swap(&hp->data[cur], &hp->data[cur * 2 + 2]);  
				cur = cur * 2 + 2;
			}
		}
		else if (cur*2+2<hp->size && hp->data[cur] < hp->data[cur * 2 + 2]){    //如果cur小于左孩子有右孩子且大于右孩子 ，和右孩子换
			swap(&hp->data[cur], &hp->data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else {
			break;                               //如果上面都不成立，结束循环
		}
	}
}
void HeapInit(Heap *hp, HPDataType *data, int n)
{
	int i;
	hp->capacity = MAXSIZE>n?MAXSIZE:n;
	hp->size = n;
	hp->data = (HPDataType *)malloc(sizeof(HPDataType)*hp->capacity);    //malloc判空，传入参数也要判空
	memcpy(hp->data, data, sizeof(HPDataType)*n);

	for (i = n/2-1; i >= 0; i--)
	{
		DownAdjust(hp, i);
	}
}
void HeapDestory(Heap *hp)
{
	if (hp->data)
	{
		free(hp->data);
		hp->data = NULL;
		hp->size = hp->capacity = 0;
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->size;
	if (hp->size == hp->capacity){
		hp->capacity *= 2;
		hp->data = (HPDataType *)realloc(hp->data, hp->capacity*sizeof(HPDataType));
	}
	hp->data[hp->size] = x;
	hp->size++;
	while (cur){
		if (hp->data[cur] > hp->data[(cur - 1) / 2])
		{
			swap(&hp->data[cur], &hp->data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else{
			break;
		}
	}
}
void HeapPop(Heap *hp)
{
	swap(hp->data, hp->data + hp->size - 1);
	hp->size--;
	DownAdjust(hp, 0);
}
HPDataType HeapTop(Heap *hp)
{
	if (hp->size == 0)
	{
		return (HPDataType)0;
	}
	return hp->data[0];
}
int HeapSize(Heap *hp)
{
	return hp->size;
}
int HeapEmpty(Heap *hp)
{
	return hp->size == 0;
}
void HeapPrint(Heap *hp)
{
	int i;
	int tag=0;
	int tmp = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == tag)
		{
			printf("\n");
			tmp *= 2;
			tag += tmp;
		}

	}
	
}

void HeapSort(Heap *hp)
{
	int tmp = hp->size;
	while (hp->size >1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;

}