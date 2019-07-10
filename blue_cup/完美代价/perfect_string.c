#define _CRT_SECURE_NO_WARNINGS 1
//输入字符串，通过交换相邻的字符将该字符串变为回文串，若变不成输出不可能，若可以，输出最少交换次数及交换后的字符串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
int Change(char a[],char x,int n)
{
	int count=0;
	int i, j,k;
	for (i = 0; i < n / 2; i++)
	{
		
		if (a[i]==x)
		{
			for (j = i; j <n-1- i; j++)
			{
				if (a[j] == a[n - 1 - i])
					break;
			}
			count += j - i;
			for (k = j; k >i; k--)
			{
				a[k] = a[k-1];
			}
			a[i] = a[n - 1 - i];

		}
		else
		{
			for (j = n - 1 - i; j > i; j--)
			{
				if (a[j] == a[i])
					break;
			}
			count += n-1-i-j;
			for (k = j; k < n - 1 - i; k++)
			{
				a[k] = a[k + 1];
			}
			a[n - 1 - i] = a[i];
		}
	}
	return count;


}
int main()
{
	char a[N];
	int b[26];
	int n;
	int i,j,k=0;
	char x;
	memset(b, 0, sizeof(b));
	gets(a);
	n=strlen(a);
	for (i = 0; i < n; i++)
	{
		j = a[i] - 'a';
		b[j] ^= 1;
	}
	for (i = 0; i < 26; i++)
	{
		if (1 == b[i])
		{
			x = i + 'a';
			k++;
		}
		if (k>1)
		{
			break;
		}
	}
	if (k > 1)
	{
		printf("impossible\n");
	}
	else
	{
		printf("可交换次%d得到完美字符串\n", Change(a, x, n));
		printf("交换后的字符串为：%s\n", a);
	}
	
	





	system("pause");
	return 0;
}