#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 30



void FF(int *arr, int len)
{
	int low=0,high=len-1;
	while (low < high)
	{
		while (1==(arr[low]%2)&&low<high)
		{
			low++;
		}
		while (0 == (arr[high] % 2)&&low<high)
		{
			high--;
		}
		if (low < high)
		{
			arr[low] ^= arr[high];
			arr[high] ^= arr[low];
			arr[low] ^= arr[high];
		}
	}
}
int main()
{
	int a[N];
	int number,i;
	printf("ÊäÈëÅÅÐò¸öÊý: ");
	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		scanf("%d", &a[i]);
	}
	FF(a, number);
	for (i = 0; i < number; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}