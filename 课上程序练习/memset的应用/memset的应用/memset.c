#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char arr[20] = "hello bit";
	memset(arr, '*', 5);        //arr��������һ��ָ�룬=&a��0���������5���ַ����滻Ϊ*
	printf("%s\n", arr);
	system("pause");



	return 0;
}