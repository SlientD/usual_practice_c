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
////12
//typedef char STRING[255];
////16
//void Fun(char str[2])
//{
//	int m = sizeof(str);
//	int n = strlen(str);
//	printf("%d,%d", m, n);
//}
//27
//int f(int x, int y)
//{
//	return (x&y) + ((x^y) >> 1);
//}
int main()
{
	int arr[] = { 6, 7, 8, 9, 10 };
	int *ptr = arr;
	*(ptr++) += 123;
	printf("%d %d", *ptr, *(ptr++));
	//27
	/*int result = f(2, 4);
	printf("%d", result);*/

	//26
	/*char str[8] = "good!";
	char str1[2] = {'g','o'};*/
	//25
	/*int i, x, y;
	i = x = y = 0;
	do{
		++i;
		if (i % 2)
		{
			x += i,
				i++;
		}
		y += i++;
	} while (i <= 7);
		printf("%d %d %d", i, x, y);*/
	
	//24
	//printf("%f", (double)(10 / 4 ));
	//23
	/*char ch = -1;
	printf("%d", ch);*/

	//22
	/*int i = 10;
	long long t = sizeof(i++);
	printf("%d", i);*/
	//21
	/*char *c = "abce";
	c += 2;
	printf("%lu\n", c);*/
	//20
	/*unsigned short x = 0;
	x--;
	printf("%d", x);*/

	//19
	/*int x = 1, y = 012;
	printf("%d", y*x++);*/


	//18
	/*char a[] = "abc";
	char *s1 = "abc";
	char *s2 = "abc";
	a[2] = 'a';
	printf("%s", a);
	printf("%p,%p", s1, s2);*/



	////17
	//union X
	//{
	//	int x;
	//	char y[4];
	//}a;
	//a.x=0x11223344;
	////printf("%x", a.y);    //y输出44   低数据位存放在低地址位是小端存储方式
	//printf("%x", a.y[33]);
	////16
	//char str[] = "Hello";
	//Fun(str);

	//15
	/*int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);
	printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);*/

	//14
	/*unsigned long ulA = 0x11000000;
	printf("%x\n", *(unsigned char*)&ulA);*/

	//13
	/*int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);*/

	
	//12
	//STRING s;      //s为一个大小为255的字符数组
	


	//11
	/*char s[] = "\\123456\123456\t";
	printf("%d", strlen(s));*/


	//10
	/*char *p = "blue1";
	char a[] = "blue1";
	printf("%d ", strlen(a));
	printf("%d ", strlen(p));
	printf("%d ", sizeof(p));
	printf("%d ", sizeof(a));*/


	////9
	//char a = 1;
	//int b = 1;
	//float c = 1.0;
	//double d = 1.0;
	



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