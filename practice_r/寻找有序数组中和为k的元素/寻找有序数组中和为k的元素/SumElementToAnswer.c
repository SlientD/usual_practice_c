#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


void SumOfAnswer(int *arr, int len, int k, int *x, int *y)
{
	
	int left=0, right=len-1;
	int sum = arr[left] + arr[right];
	while (sum != k&&left<right&&left>=0&&right<len)
	{
		if (sum > k)
		{
			right--;
		}
		else if (sum < k)
		{
			left++;
		}
		sum = arr[left] + arr[right];
	}
	if (left<right&&left >= 0 && right<len){
		*x = left;
		*y = right;
	}
	else{
		*x = -1;
		*y = -1;
	}
	


}

int main()
{
	int arr[] = { 1, 3, 5, 6, 8, 9, 10, 13 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 155;
	int x, y;
	SumOfAnswer(arr, len, k,&x, &y);
	printf("%d,%d\n", x, y);
	
	

	system("pause");
	return 0;

}