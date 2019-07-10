#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned int reverse_bit(unsigned int value)    //没有unsigned的话默认为有符号的
{
	unsigned int value1 = 0;
		int i,n;
	for (i = 0; i < 32; i++)
	{
		n = (value >> i) & 1;
		value1 += n*(int)pow(2, 31-i);         
	}
	return value1;

}
int main()
{
	unsigned int x,y;
	scanf("%d", &x);
	y=reverse_bit(x);
	printf("%u\n", y);

	system("pause");
	return 0;
}