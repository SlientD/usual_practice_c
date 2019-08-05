#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int sum1(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;


}

int main()
{
	unsigned int n;
	int count;
	scanf("%d", &n);
	count=sum1(n);
	printf("%d", count);
	system("pause");
	return 0;
}