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
		printf("��%d�������ǻ�����\n", n);
	}
	else
	{
		printf("��%d�����в��ǻ�����\n", n);
	}

	system("pause");
	return 0;
}