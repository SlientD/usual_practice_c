#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 10

int couculateM(int x, int y)
{
	int r;
	while (y)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}
int main(){
	int n, m, k, i, b, b1, t, j;
	int a[N];
	printf("输入数组中数的个数：");
	scanf("%d", &n);
	printf("\n输入数的移动步数：");
	scanf("%d", &k);;
	printf("\n输入每个数字：");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	m = couculateM(n, k);
	for (i = 0; i < m; i++)
	{
		b = a[(i+(n/m-1)*k)%n];
		t = i + (n / m - 1)*k;
		for (j = n/m; j >0; j--)
		{
			
			a[t%n] = a[(t - k) % n];
			t = t - k;
		}
		a[i] = b;

	}
	printf("\n移动后输出：");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}