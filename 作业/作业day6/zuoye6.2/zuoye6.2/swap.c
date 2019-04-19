#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//两种错误的
//void swap1(int *a, int *b)   //交换的是地址  只不过a指向j（a里存的是j的地址），b指向i；
//{
//	int *temp;               //野指针   没有初始化
//	temp = a;
//	a = b;
//	b = temp;
//}
//


//void swap(int a, int b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}


void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a = *b;
	*b = temp;
}

int main()
{
	int i=1, j=2;
	swap(&i, &j);
	printf("i=%d,j=%d", i, j);


	system("pause");
	return 0;
}