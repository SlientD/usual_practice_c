#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
int main()
{
	int n,i,j;
	scanf("%d", &n);
	int len = 1;
	int a[MAX] ;
	int d = 0;
	int max = log(n)*n / 5 + 2;
	for (i = 0; i <max; i++)
	{
		a[i]=0;
	}
	a[0] = 1;

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < len; j++){
			a[j] = a[j] * i + d;
			d = a[j] / 10000;
			a[j] = a[j] % 10000;

		}
		if (d)
		{
			len++;
		}
	}

	for (i = len-1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}


	system("pause");
	return 0;
}