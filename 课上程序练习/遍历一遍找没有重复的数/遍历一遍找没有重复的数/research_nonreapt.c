#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int FIN(int arr[], int n)
{
	int i,t=0;
	for (i = 0; i < n; i++)
	{
		t ^= arr[i];                              //�����������=0
	}
	return t;
}


int main()
{



	//��һ��û�ظ���
	int arr[11] = { 1, 1, 3, 3, 2, 5, 6, 5, 4, 4, 6 };
	int num = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	num = FIN(arr, len);
	printf("%d\n", num);
	
	system("pause");
	return 0;
}