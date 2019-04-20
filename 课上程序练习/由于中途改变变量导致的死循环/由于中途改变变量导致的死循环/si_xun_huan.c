#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i <= 12; i++)
	{
		printf("hehehe\n");
		a[i] = 0;               //可调试，发现a【12】里存的是i的值
	}


	system("pause");
	return 0;
}