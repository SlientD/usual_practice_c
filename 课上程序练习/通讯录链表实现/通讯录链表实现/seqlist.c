
#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->capacity = capacity;
	psl->array = (SLDataType *)calloc(psl->capacity, (psl->capacity)*sizeof(SLDataType));
	psl->size = 0;

}
void SeqListDestory(SeqList* psl)
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->capacity = 0;
	psl->size = 0;

}
void CheckCapacity(SeqList* psl)
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity <<= 1;   //就是乘二
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity*sizeof(SLDataType));
	}

}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	(psl->size)++;

}
void SeqListPopBack(SeqList* psl)
{

	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)  //头插
{
	CheckCapacity(psl);
	int i;

	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;


}
void SeqListPopFront(SeqList* psl){                           //时间复杂度O(n)
	int i;
	for (i = 0; i < (psl->size - 1); i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)                //时间复杂度O（n）
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return 0;


}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	CheckCapacity(psl);
	int i;

	for (i = psl->size - 1; i >= pos; i--)                //时间复杂度O（n）
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->array[pos] = x;
	psl->size++;

}
void SeqListErase(SeqList* psl, size_t pos)              //时间复杂度O（n）
{
	int i;
	for (i = pos; i <psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)          //时间复杂度O（n）
{
	SeqListErase(psl, SeqListFind(psl, x));
}
void SeqListAllRemove(SeqList* psl, SLDataType x)
{
	//法一：
	int gap = 0;
	int i;
	for (i = 0; i < psl->size - gap; i++)
	{
		while (psl->array[i + gap] == x)
		{
			gap++;


		}
		//if ((i + gap)>psl->capacity)   //若删除的数要在最后，就会溢出，判断 
		//{
		//	break;
		//}
		psl->array[i] = psl->array[i + gap];   //就算溢出这一步做了，可是下一个操作size-gap ，也会把赋溢出值的空间内容给剪掉啊？
	}
	psl->size -= gap;

	//法二：
	/*SLDataType* tmp = (SLDataType *)calloc(psl->size, psl->size*sizeof(SLDataType));
	int i, j;
	for (i = 0, j = 0; i < psl->size; i++)
	{
	if (psl->array[i] != x)
	{
	tmp[j] = psl->array[i];
	j++;
	}
	}
	free(psl->array);
	psl->array = tmp;
	psl->size = j;*/

	//printf("psl的size：%d\n", psl->size);
}


void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->array[pos] = x;

}
void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		ContactPrint(psl->array[i]);
	}
	putchar('\n');


}
// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl)
{
	int i, j, temp;
	for (i = 0; i < psl->size; i++)
	{
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				temp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = temp;
			}
		}

	}


}
int SeqListBinaryFind(SeqList* psl, SLDataType x)   //从小到大排序
{
	int start = 0;
	int end = psl->size - 1;
	int mid;
	while (start<end)
	{
		mid = (start + end) / 2;
		if (psl->array[mid]>x)
		{
			end = mid - 1;
		}
		else if (psl->array[mid] < x)
		{
			start = mid + 1;
		}
		else if (psl->array[mid] == x)
		{
			return mid;
		}
	}
	return -1;


}