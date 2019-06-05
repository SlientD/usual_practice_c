#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。

int main()
{
	int money=40,number=40,count=40;
	while ( number > 1)
	{
		count += number / 2;
		number = number / 2 + number % 2;
		
	}
	printf("%d\n", count);

//20+10+5+2+1+1
//实际为2*money-1，因为每次空瓶数都为上一次的数目/2。
	system("pause");
	return 0;

}