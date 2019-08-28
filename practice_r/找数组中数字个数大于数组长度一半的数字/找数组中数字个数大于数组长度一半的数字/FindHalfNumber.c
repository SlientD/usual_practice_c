#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define null -1

int QuickSortOne(int *a, int right, int left)        
{

	int x = a[right];


	while (right < left)
	{
		while (x<a[left] && right < left)
		{
			left--;
		}
		if (right < left)
		{
			a[right] = a[left];
		}

		while (x >= a[right] && right < left)
		{
			right++;
		}
		if (right < left)
		{
			a[left] = a[right];
		}

	}
	a[left] = x;
	return left;

}




int FindNumber(int *a,int len)
{
	int i=0,k,count=0;
	int start = 0, end = len - 1;
	while (i != len/2)
	{
		i = QuickSortOne(a, start, end);
		if (i < len / 2)
		{
			start = i + 1;
		}
		else if (i>len / 2)
		{
			end = i - 1;
		}
	}
	k = a[i];
	for (i = 0; i < len; i++)
	{
		if (a[i] == k)
		{
			count++;
		}
	}
	if (count>len / 2)
	{
		return k;
	}
	else{
		return null;
	}



}

int main()
{
	int a[] = { 1, 2, 2, 2, 2, 9,13, 2, 3, 4,4, 2, 2 };
	int x;
	int length = sizeof(a) / sizeof(a[0]);
	x = FindNumber(a,length);
	if (x == null)
	{
		printf("Dont't exist the number in array!\n");
	}
	else{
		printf("The number is %d\n", x);
	}
	

	system("pause");
	return 0;
}