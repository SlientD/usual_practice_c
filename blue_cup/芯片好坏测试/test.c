#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
	int n,i,j,sum;
	int a[N][N];
	printf("输入芯片个数:\n");
	scanf("%d", &n);
	printf("输入芯片测试数据：\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (j = 1; j <= n; j++)
	{
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			sum += a[i][j];
		}
		if (sum > (n / 2))                           //j相同时，是所有芯片测第j个芯片的结果，若一半的以上的测得该芯片结果为1，则该芯片是好的，否则这一半以上的芯片都是不好的，不符题意。
		{
			printf("%d ",j);
		}

	}




	system("pause");
	return 0;
}