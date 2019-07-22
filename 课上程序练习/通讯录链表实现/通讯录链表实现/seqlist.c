
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
		psl->capacity <<= 1;   //���ǳ˶�
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
void SeqListPushFront(SeqList* psl, SLDataType x)  //ͷ��
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
void SeqListPopFront(SeqList* psl){                           //ʱ�临�Ӷ�O(n)
	int i;
	for (i = 0; i < (psl->size - 1); i++)
	{
		psl->array[i] = psl->array[i + 1];
	}

	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)                //ʱ�临�Ӷ�O��n��
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

	for (i = psl->size - 1; i >= pos; i--)                //ʱ�临�Ӷ�O��n��
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->array[pos] = x;
	psl->size++;

}
void SeqListErase(SeqList* psl, size_t pos)              //ʱ�临�Ӷ�O��n��
{
	int i;
	for (i = pos; i <psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)          //ʱ�临�Ӷ�O��n��
{
	SeqListErase(psl, SeqListFind(psl, x));
}
void SeqListAllRemove(SeqList* psl, SLDataType x)
{
	//��һ��
	int gap = 0;
	int i;
	for (i = 0; i < psl->size - gap; i++)
	{
		while (psl->array[i + gap] == x)
		{
			gap++;


		}
		//if ((i + gap)>psl->capacity)   //��ɾ������Ҫ����󣬾ͻ�������ж� 
		//{
		//	break;
		//}
		psl->array[i] = psl->array[i + gap];   //���������һ�����ˣ�������һ������size-gap ��Ҳ��Ѹ����ֵ�Ŀռ����ݸ���������
	}
	psl->size -= gap;

	//������
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

	//printf("psl��size��%d\n", psl->size);
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
// ��չ������ʵ��
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
int SeqListBinaryFind(SeqList* psl, SLDataType x)   //��С��������
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