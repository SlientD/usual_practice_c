#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void FindNumber(int *arr,int len)
{
	int num1=0, num2=0;
	int i;
	int tmp=0;
	int pos = 0;

	for (i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}
	while ((tmp&1)==0)
	{
		tmp = tmp >> 1;
		pos++;
	}
	for (i = 0; i < len; i++)
	{
		if ((arr[i] >> pos & 1) == 0)
		{
			num1 ^= arr[i];
		}
		else{
			num2^=arr[i];
		}
	}
	printf("%d,%d\n", num1, num2);
}

int main(){
	int arr[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	FindNumber(arr, len);



	system("pause");
	return 0;
}