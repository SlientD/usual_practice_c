#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("short型：%d\n", sizeof(short));
	printf("int型：%d\n", sizeof(int));
	printf("long型：%d\n", sizeof(long));
	printf("long long型：%d\n", sizeof(long long));
	printf("char型：%d\n", sizeof(char));
	printf("double型：%d\n", sizeof(double));
	printf("float型：%d\n", sizeof(float));

	printf("short*型：%d\n", sizeof(short*));
	printf("int*型：%d\n", sizeof(int*));
	printf("long*型：%d\n", sizeof(long*));
	printf("long long*型：%d\n", sizeof(long long*));
	printf("char*型：%d\n", sizeof(char*));
	printf("double*型：%d\n", sizeof(double*));
	printf("float*型：%d\n", sizeof(float*));
	




	system("pause");
	return 0;
}