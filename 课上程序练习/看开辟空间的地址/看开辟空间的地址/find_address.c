#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 10;
	int *p = &a;
	*p = 20;
	printf("%x,%d\n", p,a);    //每次运行p的值都不一样，因为每次运行都会给a重复新开辟一个空间，p再存新a的地址
	system("pause");
	return 0;
}
