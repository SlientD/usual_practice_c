#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->arr = (SeqDataType *)calloc(capacity, capacity*sizeof(SeqDataType));
	if (psl->arr){
		printf("Init successfully!\n");
	}
	else
	{
		printf("Init unsuccessfully!\n");
		return;
	}
	psl->size = 0;
	psl->capacity = capacity;
}


void CheckCapacity(SeqList* psl)
{
	if ((psl->size + 1) > psl->capacity)
	{
		psl->capacity = 2 *( psl->capacity);
		psl->arr = (SeqDataType *)realloc(psl->arr,psl->capacity*sizeof(SeqDataType));
		if (psl->arr)
		{
			printf("expand capacity successfully!\n");
		}
		else
		{
			printf("expand capacity unsuccessfully!\n");
			return;
		}

	}
	
}
void SeqListPushBack(SeqList* psl, SeqDataType x)
{
	CheckCapacity(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SeqDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i > 0; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl){
	int i;
	for (i = 1; i <psl->size; i++)
	{
		psl->arr[i-1] = psl->arr[i];
	}
	psl->size--;

}
int SeqListFind(SeqList* psl, SeqDataType x){
	int i;
	for (i = 0; i <psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//在数组下标为pos的地方插入元素x
void SeqListInsert(SeqList* psl, size_t pos, SeqDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i > pos; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[i] = x;
	psl->size++;
}
//删掉数组下标为pos的值
void SeqListErase(SeqList* psl, size_t pos)
{
	int i;
	for (i = pos + 1; i < psl->size; i++)
	{
		psl->arr[i - 1] = psl->arr[i];
	}
	psl->size--;
}
//删除 所有x的值 
void SeqListRemove(SeqList* psl, SeqDataType x)
{
	int skip = 0;
	int i;
	for (i = 0; i < psl->size; i++)
	{
		while (psl->arr[skip+i] == x)
		{
			skip++;
			
		}
		psl->arr[i] = psl->arr[skip + i];
	}
	psl->size = psl->size - skip;
	/*for (i = 0; i < psl->size; i++)
	{
		while (psl->arr[i+skip] == x&&i+skip<psl->size)
		{ 
			skip++;
		}
		if (i + skip-1 >= psl->size)
		{
			break;
		}
		psl->arr[i] = psl->arr[i + skip];
		i = i + skip ;
	}
	psl->size = psl->size - skip;*/
}
void SeqListModify(SeqList* psl, size_t pos, SeqDataType x)
{
	psl->arr[pos] = x;
}
void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d->", psl->arr[i]);
	}
	printf("null\n");
}
void SeqListDestory(SeqList* psl)
{
	psl->size = 0;
	psl->capacity = 0;
	free(psl->arr);
}
void SeqListBubbleSort(SeqList* psl)
{
	int i,j,tmp;
	for (i = 0; i < psl->size; i++)
	{
		for (j = 0; j < psl->size - i-1; j++)
		{
			if (psl->arr[j+1] < psl->arr[j])
			{
				tmp = psl->arr[j+1];
				psl->arr[j+1] = psl->arr[j];
				psl->arr[j] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SeqDataType x)
{
	int right = psl->size-1, left = 0;
	int mid;
	while (right >= left)
	{
		mid = (right + left) / 2;
		if (psl->arr[mid] > x)
		{
			right = mid - 1;
		}
		else if (psl->arr[mid] < x)
		{
			left=mid+1;
		}
	
		else if (psl->arr[mid] == x)
		{
			return mid;
		}
	}
	return -1;

}