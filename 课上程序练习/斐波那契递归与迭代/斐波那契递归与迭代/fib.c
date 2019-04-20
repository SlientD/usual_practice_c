#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number;
	int first, second, third;
	scanf("%d", &number);
	first = 1;
	second = 1;
	if (number < 3)
		third = 1;
	while (number >= 3)
	{
		third = first + second;
		first = second;
		second = third;
		number--;
	}
	printf("%d\n", third);
	system("pause");
	return 0;
}