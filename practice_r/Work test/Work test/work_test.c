#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun1(int x, int y)
{
	int m = 0;
	int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);

	printf("%d\n", k);
	k = fun1(j, m);
	printf("%d\n", k);






	/*enum A{
		X1,
		X2,
		X3 = 5,
		X4
	};
	printf("%d,%d", X1, X4);*/
	/*struct A1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct A2
	{
		long b;
		short a;
		char d;
		long c;
	};
	struct A3
	{
		short a;
		long b;
		char d;
		long c;
	};
	printf("%d,%d,%d,%d", sizeof(long),sizeof(struct A1), sizeof(struct A2), sizeof(struct A3));*/



	/*int a[20];
	int *p1 = (char *)a;
	int *p2 = (char *)(a + 5);
	int n = p2 - p1;
	printf("%d", n);*/




	/*char a[] = "hello\0world";
	char b[15] = { 0 };
	strcpy(b, a);

	printf("%d\n", strlen(b));
	printf("%d\n", sizeof(a));*/



	/*double **a[3][4];
	printf("%d", sizeof(a));*/


	/*int a = 2;
	printf("%d", a++);*/

	system("pause");
	return 0;
}