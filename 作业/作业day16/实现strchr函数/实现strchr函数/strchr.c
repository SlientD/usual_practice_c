#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char* My_Strchr(const char* string, int num)
{
	assert(string != NULL);
	for (string; string !=0; string++)
	{
		if (*string == num)
		{
			return string;
		}
	}
	return NULL;
}
int main()
{
	char a[] = "abcd";
	char b = 'b';
	char* c;
	//if (strchr(a, b) == 0)
	if (My_Strchr(a, b) == 0)
		printf("a中没有b\n");
	else
		printf("a中有b\n");
	c = strchr(a, b);
	printf("%p\n%p\n", c,a+1);
	system("pause");
	return 0;
}