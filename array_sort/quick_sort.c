#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 3
void Input(int arr[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

}


int QPass(int arr[], int low, int high)
{
	int x = arr[low];
	while (low < high)
	{

		while (x < arr[high] && low < high)
		{
			high--;
		}
		if (low < high)
		{
			arr[low] = arr[high];
			low++;
		}

		while (x > arr[low] && low < high)
		{
			low++;
		}
		if (low < high)
		{
			arr[high] = arr[low];
			high--;
		}
		arr[low] = x;
		return low;
	}
	return low;
}
void QuickSort(int arr[],int low,int high)
{
	
	int pos;
	if (low < high)
	{
		pos=QPass(arr,low , high);
		QuickSort(arr, low, pos-1);
		QuickSort(arr, pos + 1, high);
	}

}
int main()
{
	int i;

	int arr[N];
	Input(arr);
	QuickSort(arr,0,N-1);
	for (i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
