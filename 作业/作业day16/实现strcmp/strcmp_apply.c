#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int My_StrnCmp(const char*str1, const char*str2,int k)
{

	assert(str1 != NULL&&str2 != NULL);

	while (*str1 == *str2&&k--)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return 0;
	}

	else if (*str1 > *str2)
		return 1;
	else
		return -1;

}
int My_StrCmp(const char*str1, const char*str2)
{
	
	assert(str1 != NULL&&str2 != NULL);
	
		while (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str1 == *str2)
		{
			return 0;
		}
	
		else if (*str1 > *str2)
			return 1;
		else
			return -1;

}
int main()
{
	//strcmp�Ƚϣ�ǰ�ߴ󷵻�1���ߴ󷵻�-1����ȷ���0����С�ͱȽϣ�������ͬ�ַ�ʱ���Ƚ�����ַ��Ĵ�С
	//printf("%d\n", strcmp("abcd", "abcd"));   //0
	//printf("%d\n", strcmp("abdd", "abcd"));   //1
	//printf("%d\n", strcmp("abcd", "abdd"));   //-1

	char*a = "abc";
	char b[] = "abcdef";
	//if (strcmp(a, b) == 0)
	if (My_StrCmp(a, b) == 0)
		printf("same\n");
	else
	{
		printf("different\n");
	}
	int ret = My_StrCmp(a, b);
	printf("%d\n",ret);
	system("pause");
	return 0;
}