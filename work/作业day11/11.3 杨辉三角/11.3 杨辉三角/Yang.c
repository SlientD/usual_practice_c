#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
	int yang[N][N];
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		yang[i][i] = 1;
		yang[i][0] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			yang[i][j] = yang[i - 1][j - 1] + yang[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-4d", yang[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}