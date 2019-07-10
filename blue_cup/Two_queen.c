#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define M 4

int a[M][M];
int col1[M], digr1[2 * M], digl1[2 * M];
int col2[M], digr2[2 * M], digl2[2 * M];
int sum = 0;
int N;


void PLACE2(int row2)
{
	int colb;
	if (row2 == N+1)
	{
		sum++;

	}
	else{
		for (colb = 1; colb <= N; colb++)
		{
			if (a[row2][colb] != 0 && col2[colb] != 0 && digr2[N - row2 + colb] != 0 && digl2[row2 + colb] != 0)
			{
				a[row2][colb] = 0;
				col2[colb] = 0;
				digr2[N - row2 + colb] = 0;
				digl2[row2 + colb] = 0;
				PLACE2(row2 + 1);
				a[row2][colb] = 1;
				col2[colb] = 1;
				digr2[N - row2 + colb] = 1;
				digl2[row2 + colb] = 1;

			}

		}
	}

}
void PLACE1(int row)
{
	int col;
	if (row == N+1)
	{
		int colb, row2=1;
		for (colb = 1; colb <= N; colb++)
		{
			if (a[row2][colb] != 0 && col2[colb] != 0 && digr2[N - row2 + colb] != 0 && digl2[row2 + colb] != 0)
			{
				a[row2][colb] = 0;
				col2[colb] = 0;
				digr2[N - row2 + colb] = 0;
				digl2[row2 + colb] = 0;
				PLACE2(row2 + 1);
				a[row2][colb] = 1;
				col2[colb] = 1;
				digr2[N - row2 + colb] = 1;
				digl2[row2 + colb] = 1;

			}

		}
		


	}
	else{
		for (col = 1; col <= N; col++)
		{
			if (a[row][col] != 0 && col1[col] != 0 && digr1[N - row + col] != 0 && digl1[row + col] != 0)
			{
				a[row][col] = 0;
				col1[col] = 0;
				digr1[N - row + col] = 0;
				digl1[row + col] = 0;
				PLACE1(row + 1);
				a[row][col] = 1;
				col1[col] = 1;
				digr1[N - row + col] = 1;
				digl1[row + col] = 1;
			}


		}
	}

}
int main()
{
	int i, j;
	int row = 1,col=1;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		col1[i] = 1;
		col2[i] = 1;
		for (j = 1; j <= N; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (i = 0; i <= 2 * N ; i++)
	{
		digr1[i] = 1;
		digl1[i] = 1;
		digr2[i] = 1;
		digl2[i] = 1;

	}
	
	
	for (col = 1; col <= N; col++)
	{
		if (a[row][col] != 0 && col1[col] != 0 && digr1[N - row + col] != 0 && digl1[row + col] != 0)
		{
		
		a[row][col] = 0;
		col1[col] = 0;
		digr1[N - row + col] = 0;
		digl1[row + col] = 0;
		PLACE1(row + 1);
		a[row][col] = 1;
		col1[col] = 1;
		digr1[N - row + col] = 1;
		digl1[row + col] = 1;
		}
	}

	printf("%d\n", sum);
	system("pause");
	return 0;
}