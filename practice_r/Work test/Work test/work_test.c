#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>









//6
//int fun1(int x, int y)
//{
//	int m = 0;
//	int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//}
//int fun(int x, int y)
//{
//	static int m = 0;
//	static int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//}

//7
//unsigned long g_ulGlobal = 0;
//void GlobalInit(unsigned long ulArg)
//{
//	ulArg = 0x01;
//	return;
//}


//8
//int x = 3;
//void inc()
//{
//	static int x = 1;
//	x *= (x + 1);
//	printf("%d", x);
//	return;
//}
int main()
{

	//9
	char a = 1;
	int b = 1;
	float c = 1.0;
	double d = 1.0;
	



	//8
	/*int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}*/

	//7
	/*int a = 4;
	printf("%d", ++(a++));*/
	/*GlobalInit(g_ulGlobal);
	printf("%d", g_ulGlobal);*/
	


	//6
	/*int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);

	printf("%d\n", k);
	k = fun1(j, m);
	printf("%d\n", k);*/





	//5
	/*enum A{
		X1,
		X2,
		X3 = 5,
		X4
	};
	printf("%d,%d", X1, X4);*/

	//4
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


	//4
	/*int a[20];
	int *p1 = (char *)a;
	int *p2 = (char *)(a + 5);
	int n = p2 - p1;
	printf("%d", n);*/



	//3
	/*char a[] = "hello\0world";
	char b[15] = { 0 };
	strcpy(b, a);

	printf("%d\n", strlen(b));
	printf("%d\n", sizeof(a));*/


	//2
	/*double **a[3][4];
	printf("%d", sizeof(a));*/

	//1
	/*int a = 2;
	printf("%d", a++);*/

	system("pause");
	return 0;
}