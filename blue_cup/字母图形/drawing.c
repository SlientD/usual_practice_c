#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10
#define N 10

int main()
{
	int m, n,i,j;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", abs(j - i) + 65);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}