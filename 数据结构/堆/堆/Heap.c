#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#define ARRSIZE(a)  (sizeof(a)/sizeof(a[0]))

#include "Heap.h"
#include <string.h>
#include <stdio.h>

#if 1
void swap(HPDataType *a, HPDataType *b)  //���һ�������Լ����Լ����������Լ����Լ����ͬʱ���޸����Լ��Ķ�Ӧ��ַ�Ŀռ䣬��ֵ*a��ͬʱ�ְ�*b���ĵ��ˣ����Խ�sort��������Ϊ����һ��ֻʣһ���ڵ��ʱ�򲻽���
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
void DownAdjust(Heap *hp, int n)    //n ��Ҫ����������������е��±�
{
	int cur = n;
	while (cur*2+1<hp->size)     //���һ����û����ڵ㣬����һ����Ҷ�ӣ�ֱ������
	{
		if (hp->data[cur] < hp->data[cur * 2 + 1])       //������У�cur��������ڵ㻹С��ִ�н���
		{
			if (cur * 2 + 2>=hp->size || hp->data[2 * cur + 2] <= hp->data[cur * 2 + 1])       //����Һ��Ӳ����ڻ������Ӵ����Һ���
			{
				swap(&hp->data[cur], &hp->data[cur * 2 + 1]);     //�����ӻ�
				cur = cur * 2 + 1;                       //��λ
			}
			else{                                        //����Һ��Ӵ������ӣ����Һ��ӽ���
				swap(&hp->data[cur], &hp->data[cur * 2 + 2]);  
				cur = cur * 2 + 2;
			}
		}
		else if (cur*2+2<hp->size && hp->data[cur] < hp->data[cur * 2 + 2]){    //���curС���������Һ����Ҵ����Һ��� �����Һ��ӻ�
			swap(&hp->data[cur], &hp->data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else {
			break;                               //������涼������������ѭ��
		}
	}
}
void HeapInit(Heap *hp, HPDataType *data, int n)
{
	int i;
	hp->capacity = MAXSIZE>n?MAXSIZE:n;
	hp->size = n;
	hp->data = (HPDataType *)malloc(sizeof(HPDataType)*hp->capacity);    //malloc�пգ��������ҲҪ�п�
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