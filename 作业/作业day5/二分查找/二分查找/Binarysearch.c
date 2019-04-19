#define _CRT_SECURE_NO_WARNINGS 1
#include "Binarysearch.h"
int Binarysearch(int n, int arr[], int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (n > arr[mid])
		{
			low = mid + 1;
		}
		else if (n < arr[mid])
		{
			high = mid - 1;
		}
		else
			return mid;

	}
	return -1;
}
