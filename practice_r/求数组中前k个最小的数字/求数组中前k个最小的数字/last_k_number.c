#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 10


//方法一：利用快速排序的特性，在一次快排后，分界值得左边小于该分界值，右边大于该分界值。
//若某分界值的下标是k-1，那么分界点及分界点前的数就是该数组中最小的k个数。
//因此，该问题就变成了找分界值下标为k-1的位置，并返回 。

int QuckSortOne(int *a,int right,int left)        //返回每一次分界点的下标
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

		while (x>=a[right] && right < left)
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


void LastK(int *a,int k)              //找分界点恰好满足左边加自身一共有k个值 ，且该k个值是数组中最小k个数
{
	int start = 0;
	int end = N-1;
	int result;
	do{

		result = QuckSortOne(a,start,end);
		if (result > k)
		{
			end = result-1;
		}
		if (result < k)
		{
			start = result+1;
		}
		
	} while (result != k-1);      //为什么此处为k-1？因为result是分界值得下标，在求前N （k=N）个最小数时，最后中值的下标是N-1，所以防止越界，将result的与K-1比较

}

int main()
{
	int a[N] = { 1, 9, 2, 5, 4, 7, 8, 3, 10, 6 };
	int k,i;

	scanf("%d", &k);
	if (k > N)
	{
		printf("k is error\n");
	}
	else{
		LastK(a, k);
		for (i = 0; i < k; i++){
			printf("%d ", a[i]);
		}
	}

	system("pause");
	return 0;
}