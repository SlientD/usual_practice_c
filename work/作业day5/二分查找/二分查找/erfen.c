#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Binarysearch.h"
/*
作者：
日期：
描述：干什么，返回值。。
*/







//int Binarysearch(int n, int arr[], int low, int high)   //递归
//{
//	int mid = (low + high) / 2;
//
//	if (n > arr[mid] && low < high)
//	{
//		mid = Erfen(n, arr, mid + 1, high);
//	}
//
//	if (n < arr[mid] && low < high)
//	{
//		mid = Erfen(n, arr, low, mid - 1);
//	}
//	if (n == arr[mid])
//	{
//		return mid;
//
//	}
//	if (low >= high)
//	{
//		return -1;
//	}
//	return mid;
//
//
//}






//int Binarysearch(int n, int arr[], int low, int high     //错误代码
//{
//	int mid = (low + high) / 2;
//
//	if (n>arr[mid] && low<high)
//		Erfen(n, arr, mid + 1, high);
//
//	if (n<arr[mid] && low<high)
//		Erfen(n, arr, low, mid - 1);
//	if (n == arr[mid])
//	{
//		return mid;
//
//	}
//	if (low >= high)
//	{
//		return -1;
//	}
//}
int main()
{
	int n;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("请输入你要查找的数字:");
	scanf("%d", &n);
	int low = 0;
	int high = sizeof(a) / sizeof(a[0]) - 1;              //数组在哪定义就在那里计算长度！！！
	int t = Binarysearch(n, a, low, high);

	if (-1 == t)
		printf("没有你要找的数\n");
	else
	
		printf("下标为%d\n", t);

	system("pause");
	return 0;
}