#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number,number1;
	int count=0;
	scanf("%d", &number);
	number1 = number;
	while (number)
	{
		printf("%d ", number % 10);
		count++;
		number = number / 10;
	}
	system("pause");
	return 0;
}