#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number;
	int count = 0;
	scanf("%d", &number);
	while (number)                          //可求负数
	{
		count++;
		number = number&(number - 1);
	}



	/*int i = 0;
	while (i<32)
	{
		if (1 == ((number >> i) & 1))
			count++;
		i++;
	}*/

	printf("%d\n", count);
	system("pause");
	return 0;
}
int find(int num)
{
	int count;
	while (num)
	{
		count++;
		num = num&(num - 1);
	}



	return count;
}