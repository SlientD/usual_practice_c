#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stract(str1,str2)     把str2拼接到str1后面,两个参数不能一样
//strncat(str1,str2,n)   n为复制个数
//strstr(被查找串,查找串)  查找字符串          没有返回NULL

int is_same(char *str1, char *str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	strncat(str1, str1,strlen(str1));
	printf("%s\n", str1);
	
	if (strstr(str1, str2) != NULL)
	{
		return 1;
	}
	else return 0;
}
int main()
{
	char str1[20] = "abcdef";
	char str2[9] = "defabc";
	if (is_same(str1, str2))
	{
		printf("str2是str1旋转后得到的\n");
	}
	else
	{
		printf("str2不是str1旋转后得到的\n");
	}
	system("pause");
	return 0;
}



//int Gys(int m, int n)
//{
//	int r;
//	while (n)
//	{
//		r = m%n;
//		m = n;
//		n = r;
//	}
//	return m;
//}
//
//
//int Revolve(char *a, char *b, int k, int len, int direction)
//{
//	int m = Gys(len, k);
//	int NUM = len / m;
//	int num = NUM;
//	char temp;
//	int i, j, t;
//	for (i = len - 1; i >len - m - 1; i--)
//	{
//		num = NUM;
//		t = i;
//		j =( t + direction* k)%len;
//		temp = a[i];
//		while (--num)
//		{
//			a[t] = a[j];
//			t = j;
//			j = (j + direction* k) % len;
//		}
//		a[t] = temp;
//	}
//	printf("%s\n", a);
//	if (strcpy(a, b) == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//
//
//int main()
//{
//	char a[100], b[100];
//	int k, len, select;
//	printf("输入字符串a：");
//	gets(a);
//	printf("输入字符串b：");
//	gets(b);
//	printf("右移请输-1，左移请输1：");
//	scanf("%d", &select);
//	printf("移动个数：");
//	scanf("%d", &k);
//	len = strlen(a);
//	if (select)
//	{
//
//	}
//
//	if (Revolve(a, b, k, len, select) == 0)
//		printf("旋转后相同\n");
//	else
//		printf("旋转后不相同\n");
//
//	system("pause");
//	return 0;
//
//}