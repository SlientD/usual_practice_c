#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
char* my_strcat(char* destination, const char* source)
{
	assert(destination != NULL&&source != NULL);

	char* ret = destination;
	while (*destination)
	{
		destination++;
	}
	
	while ((*destination++ = *source++) != 0);
	return ret;

}
char* my_strcpy(char* destination, const char* source)
{
	assert(destination != NULL&&source != NULL);

	char* ret = destination;
	while ((*destination++ = *source++) != 0);
	return ret;

}
int main()
{
	char*a = "abc";
	char b[10] = "efgh";
	my_strcat(b, a);
	printf("strcat后的b=%s\n", b);
	my_strcpy(b, a);
	printf("strcpy后的b=%s\n", b);
	system("pause");
	return 0;
}