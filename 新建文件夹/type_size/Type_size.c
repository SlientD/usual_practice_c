#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("short型：%d\n", sizeof(short));           //——>2
	printf("int型：%d\n", sizeof(int));               //——>4
	printf("long型：%d\n", sizeof(long));             //——>4
	printf("long long型：%d\n", sizeof(long long));   //——>8
	printf("char型：%d\n", sizeof(char));             //——>1
	printf("double型：%d\n", sizeof(double));         //——>8
	printf("float型：%d\n", sizeof(float));           //——>4

	printf("short*型：%d\n", sizeof(short*));
	printf("int*型：%d\n", sizeof(int*));
	printf("long*型：%d\n", sizeof(long*));
	printf("long long*型：%d\n", sizeof(long long*));
	printf("char*型：%d\n", sizeof(char*));
	printf("double*型：%d\n", sizeof(double*));
	printf("float*型：%d\n", sizeof(float*));
	  
    
  //指针类型都为4




	system("pause");
	return 0;
}
