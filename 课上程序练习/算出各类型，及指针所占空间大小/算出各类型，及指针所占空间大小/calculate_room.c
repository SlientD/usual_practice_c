#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("short�ͣ�%d\n", sizeof(short));
	printf("int�ͣ�%d\n", sizeof(int));
	printf("long�ͣ�%d\n", sizeof(long));
	printf("long long�ͣ�%d\n", sizeof(long long));
	printf("char�ͣ�%d\n", sizeof(char));
	printf("double�ͣ�%d\n", sizeof(double));
	printf("float�ͣ�%d\n", sizeof(float));

	printf("short*�ͣ�%d\n", sizeof(short*));
	printf("int*�ͣ�%d\n", sizeof(int*));
	printf("long*�ͣ�%d\n", sizeof(long*));
	printf("long long*�ͣ�%d\n", sizeof(long long*));
	printf("char*�ͣ�%d\n", sizeof(char*));
	printf("double*�ͣ�%d\n", sizeof(double*));
	printf("float*�ͣ�%d\n", sizeof(float*));
	




	system("pause");
	return 0;
}