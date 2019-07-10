#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

void DEAL(int result[][N], int x[][N], int y[][N], int n)
{
	int i, j,k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
				result[i][j] += x[i][k] * y[k][j];
		}
	}
}

void print(int arr[N][N], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%-4d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[N][N], r[N][N], t[N][N];
	int n, m,i,j;
	int flag=0;
	scanf("%d%d", &n, &m);
	memset(r, 0, sizeof(r));
	

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
		r[i][i] = 1;
	}

	while (m--)
	{
		if (flag == 0)
		{
			memset(t, 0, sizeof(t));
			DEAL(t, r, a, n);
			flag = 1;
		
		}
		else if (flag == 1)
		{
			memset(r, 0, sizeof(r));
			DEAL(r, t, a, n);
			flag = 0;
		}
	}
	if (flag == 0)
	{
		print(r,n);
	}
	else if (flag == 1)
	{
		print(t, n);

	}



	system("pause");
	return 0;

}