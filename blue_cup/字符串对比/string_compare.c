#define _CRT_SECURE_NO_WARNINGS 1
//两字符串的比较有四种情况
//1.两字符串长度不同
//2.两字符串长度对应字符完全相同
//3.两字符串长度相同，但其中一些字符大小写不同
//4.两字符串长度相同，但对应字符不区分大小写时也不同
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
	printf("两字符串属于第%d种情况\n", flag);



	system("pause");
	return 0;

}