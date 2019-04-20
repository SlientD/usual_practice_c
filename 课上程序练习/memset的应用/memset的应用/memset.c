#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char arr[20] = "hello bit";
	memset(arr, '*', 5);        //arr在这里是一个指针，=&a【0】，往后的5个字符都替换为*
	printf("%s\n", arr);
	system("pause");



	return 0;
}