#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stract(str1,str2)     ��str2ƴ�ӵ�str1����,������������һ��
//strncat(str1,str2,n)   nΪ���Ƹ���
//strstr(�����Ҵ�,���Ҵ�)  �����ַ���          û�з���NULL

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
		printf("str2��str1��ת��õ���\n");
	}
	else
	{
		printf("str2����str1��ת��õ���\n");
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
//	printf("�����ַ���a��");
//	gets(a);
//	printf("�����ַ���b��");
//	gets(b);
//	printf("��������-1����������1��");
//	scanf("%d", &select);
//	printf("�ƶ�������");
//	scanf("%d", &k);
//	len = strlen(a);
//	if (select)
//	{
//
//	}
//
//	if (Revolve(a, b, k, len, select) == 0)
//		printf("��ת����ͬ\n");
//	else
//		printf("��ת����ͬ\n");
//
//	system("pause");
//	return 0;
//
//}