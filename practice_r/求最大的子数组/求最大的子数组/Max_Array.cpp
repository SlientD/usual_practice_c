#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目要求：输入一个整形数组，数组里有正数也有负数，数组中一个或多个连成一个子数组，求所有子数组的和的最大值。要求时间复杂度为O(n).
//例如：输入数组{1,-2,3,10,-4,7,2,-5},和最大子数组为{3,10,-4,7,2}，因此输出该子数组的和18

//方法一：暴力求解，定义两个变量，一个存从每个数开始相加到最后的和（sum），一个存最后子数组的最大值（final，初值为-MAX）。每次相加将final和sum比较，若sum大，则更新final的值，最后输出。
//时间复杂度O（n^2）
int MaxArray1(int *arr, int len)
{
	int sum, final = INT_MIN;
	int i,j;
	
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j < len; j++)
		{
			sum += arr[j];
			if (final < sum)
			{
				final = sum;
			}
		}
	}
	return final;
}

//方法二：贪心算法：sum中保存之前相加的，final保存最终结果，从开始，当前面子串相加为负数时，就将sum置为0(把前面的子串全部切掉，判断后面有没有出现更大的子串)，在相加过程中将sum与final作比较，当sum的值大于final时，就更新final的值
//时间复杂度O(N)
int MaxArray2(int *arr, int len)
{
	int sum=0, final = INT_MIN;
	int i;

	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		if (sum>final)
		{
			final = sum;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return final;
}

//方法三：分治+递归法
//时间复杂度：O（nlog(n)）
int MaxArray3(int *arr, int low,int high)
{
	int  left, right, center = 0,final;
	int sum = 0, max = 0, i, mid;
	if (low == high)
	{
		return arr[low];
	}
	else if (low < high)
	{
		mid = (low + high) / 2;
		left = MaxArray3(arr, low, mid);
		right = MaxArray3(arr, mid + 1, high);
		for (i = mid; i >= low; i--)
		{
			sum += arr[i];
			if (sum>max)
			{
				max = sum;
			}
		}
		center += max;
		max = INT_MIN; sum = 0;
		for (i = mid+1; i < high; i++)
		{
			sum += arr[i];
			if (sum>max)
			{
				max = sum;
			}
		}
		center += max;
		final = left > right ? left : right;
		final = final > center ? final : center;
		return final;
	}
}


int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int sum = MaxArray3(arr, 0,len-1);
	printf("The sum of max array is %d\n", sum);
	system("pause");
	return 0;

}