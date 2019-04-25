#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 6
	int fx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int fy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int a[M][N];
	int dep, x, y, count;

	void output()
	{
		count++;

		printf("count=%d\n", count);
		for (x = 1; x < M; x++)
		{
			
			for (y = 1; y < N; y++)
				printf("%-3d", a[x][y]);
			printf("\n");
		}
		printf("\n");
	}
	int check(x, y)
	{
		if (a[x][y] != 0 || x<1 || y<1 || x>=M || y>=N)
			return 0;
		else return 1;
	}
	void find(int x, int y, int dep)
	{
		int i, xx, yy;
		for (i = 0; i <8; i++)
		{
			xx = x + fx[i];
			yy = y + fy[i];

			if (check(xx, yy) == 1)
			{
				a[xx][yy] = dep;
				if (dep ==( M-1) * (N-1))
					output();
				else
					find(xx, yy, dep + 1);
			a[xx][yy] = 0;
			}

		}
	}
	
	

	int main()
	{
		int i, j;
		count = 0;
		dep = 1;
		printf("printf start <x,y>:");
		scanf("%d%d", &x, &y);
		if (x<1 || y<1 || x>M || y>N)
		{
			printf("error");
			return 0;
		}
		for (i = 1; i < M; i++)
		{
			for (j = 1; j < N; j++)
			{
				a[i][j] = 0;
			}
		}
		a[x][y] = 1;
		find(x, y, 2);
		if (count == 0)
		{
			printf("no solution");
		}
		else
			printf("count=%d\n", count);
		system("pause");
		return 0;

	}
