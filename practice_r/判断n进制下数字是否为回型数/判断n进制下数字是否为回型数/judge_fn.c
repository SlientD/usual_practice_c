#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

int main()
{
	int num, n;
	scanf("%d%d", &num, &n);
	int i = num;
	int sum = 0;
	for (i; i; i=i / 10)
	{
		sum += sum * 10 + i % 10;

	}
	if (sum == num)
	{
		printf("在%d进制中是回文数\n", n);
	}
	else
	{
		printf("在%d进制中不是回文数\n", n);
	}

	system("pause");
	return 0;
}