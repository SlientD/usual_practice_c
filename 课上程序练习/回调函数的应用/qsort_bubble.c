#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *x,const void *y)
{
	if (*(int *)x > *(int *)y)
	{
		return 1;
	}
	else return 0;


}
void swap(void*x, void* y,int size)
{
	char *px = x;
	char *py = y;
	char temp;
	int i;
	for (i = 0; i < size; i++)
	{
		temp = *(px + i);
		*(px + i) = *(py + i);
		*(py + i) = temp;

	}

}
void My_qsortOfBubble(void* arr, int len, int size, int(*cmp)(const void*, const void*))
{
	int i, j;
	int flag;
	for (i = 0; i < len-1; i++)
	{
		flag = 1;
		for (j = 0; j < len -i- 1; j++)
		{
			if (cmp((char*)arr + j*size, (char *)arr + (j + 1)*size))
			{
				flag = 0;
				swap((char*)arr + j*size, (char *)arr + (j + 1)*size,size);
			}
		}
		if (flag)
		{
			break;
		}
	}



}
int main()
{
	int arr[] = { 2, 5, 4, 1, 3, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;
	My_qsortOfBubble(arr, len, sizeof(arr[0]), cmp);
	//qsort(arr, len, sizeof(arr[0]), cmp);        //ÅÅÐòº¯Êýqsort:(void* base,int number_of_base,int size_of_element,int cmp(const void*,const void *))
	for (i = 0; i < len; i++)
	{

		printf("%d ", arr[i]);
	}







	system("pause");
	return 0;
}