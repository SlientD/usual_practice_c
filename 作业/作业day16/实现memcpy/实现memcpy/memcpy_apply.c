#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void My_Memcpy(char *dest, const char *src, int count)
{
	assert(dest != NULL&&src != NULL);
	char * ret = dest;
	while (count--)
	{
		
		*dest = *src;
		dest++;
		src++;
	}

}

int main()
{
	char a[] = "1254567";
	char b[] = "1244569";
	//int ret = memcmp(a, b,7);
	//printf("%d\n", ret);
	memcpy(a+2, a, 3);                     //?
	//My_Memcpy(a + 2, a, 3);
	printf("%s\n", a);

	system("pause");
	return 0;

}