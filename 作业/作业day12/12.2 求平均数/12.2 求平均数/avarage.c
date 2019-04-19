#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a ,b;
	double c;
	scanf("%d%d", &a,&b);
	c = (a&b) + (a^b) >> 1; 
	//c = a + (b - a)/2.0;
	printf("%f\n", c);
	system("pause");
	return 0;
}