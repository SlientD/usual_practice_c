#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 10;
	int *p = &a;
	*p = 20;
	printf("%x,%d\n", p,a);    //ÿ������p��ֵ����һ������Ϊÿ�����ж����a�ظ��¿���һ���ռ䣬p�ٴ���a�ĵ�ַ
	system("pause");
	return 0;
}
