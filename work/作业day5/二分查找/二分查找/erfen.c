#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Binarysearch.h"
/*
���ߣ�
���ڣ�
��������ʲô������ֵ����
*/







//int Binarysearch(int n, int arr[], int low, int high)   //�ݹ�
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






//int Binarysearch(int n, int arr[], int low, int high     //�������
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
	printf("��������Ҫ���ҵ�����:");
	scanf("%d", &n);
	int low = 0;
	int high = sizeof(a) / sizeof(a[0]) - 1;              //�������Ķ������������㳤�ȣ�����
	int t = Binarysearch(n, a, low, high);

	if (-1 == t)
		printf("û����Ҫ�ҵ���\n");
	else
	
		printf("�±�Ϊ%d\n", t);

	system("pause");
	return 0;
}