#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
	int n,i,j,sum;
	int a[N][N];
	printf("����оƬ����:\n");
	scanf("%d", &n);
	printf("����оƬ�������ݣ�\n");
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
		if (sum > (n / 2))                           //j��ͬʱ��������оƬ���j��оƬ�Ľ������һ������ϵĲ�ø�оƬ���Ϊ1�����оƬ�Ǻõģ�������һ�����ϵ�оƬ���ǲ��õģ��������⡣
		{
			printf("%d ",j);
		}

	}




	system("pause");
	return 0;
}