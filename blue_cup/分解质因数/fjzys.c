#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a, b;
	int i, j,k;
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++)
	{
		printf("%-2d=", i);
		k = i;
		for (j = 2; j <= i/2; j++)
		{
			while (k%j == 0)
			{
				k = k / j;
				if (1 == k)
				{
					printf("%-2d", j);
					break;
				}
				else
				{
					printf("%-2d*", j);
				}

			}
			
		}
		if (k == i)
		{
			printf("%-3d", k);
		}
		printf("\n");

	}
	



	system("pause");
	return 0;
}