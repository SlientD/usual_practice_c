#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char str1[] = "abcde";                  //������
	char *str2="abcde";                  //����Ϊ�ַ�������Ϊ�ַ�������ReadOnly��
	int i=0;
	while (str1[i] != '\0')
	{
		printf("%c", str1[i]);
		i++;	
	}
	printf("\n");
	while (*str2 != '\0')
	{
		printf("%c", str2);
		printf("%c\n", *str2);
		str2++;
	}


	system("pause");
	return 0;
}