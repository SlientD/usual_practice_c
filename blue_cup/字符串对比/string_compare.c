#define _CRT_SECURE_NO_WARNINGS 1
//���ַ����ıȽ����������
//1.���ַ������Ȳ�ͬ
//2.���ַ������ȶ�Ӧ�ַ���ȫ��ͬ
//3.���ַ���������ͬ��������һЩ�ַ���Сд��ͬ
//4.���ַ���������ͬ������Ӧ�ַ������ִ�СдʱҲ��ͬ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100 

int main()
{
	char a[N], b[N];
	int flag,i;
	int len1, len2;
	gets(a);
	gets(b);
	len1 = strlen(a);
	len2 = strlen(b);
	if (len1 != len2)
	{
		flag = 1;
	}
	else if (strcmp(a, b) == 0)
	{
		flag = 2;
	}
	else
	{
		flag = 3;
		for (i = 0; i < len1; i++)
		{
			if (abs(a[i] - b[i]) != 32 && (a[i] - b[i]) != 0)
			{
				flag = 4;
			}
		}
	}
	printf("���ַ������ڵ�%d�����\n", flag);



	system("pause");
	return 0;

}