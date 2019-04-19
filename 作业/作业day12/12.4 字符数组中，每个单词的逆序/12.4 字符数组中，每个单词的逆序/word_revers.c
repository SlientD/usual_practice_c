#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int MYSTRLEN(char *arr)
{
	assert(arr != NULL);
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}
void reverse1(char *arr, char* low,char* high)
{
	assert(arr != NULL);
	char temp;
	if ((high-low)>=1)
	{
		temp = *low;
		*low = *high;
		*high = '\0';
		reverse1(arr + 1, low+1, high-1);
		*high = temp;
	}
}
void reverse(char *arr, char* low, char*high)
{
	char* i = arr;
	char* t = arr;
	
	reverse1(arr, low, high);
	printf("%s\n", arr);
	//system("pause");

	while (*i != '\0')
	{
		i = t;
		while (*i != ' '&&*i != '\0')
			i++;
		reverse1(arr, t, i - 1);
		t = i + 1;


	}



}
int main()
{
	char arr[100];
	
	gets(arr);
	int len = MYSTRLEN(arr);
	char *low = arr;
	char *high = len+arr - 1;
	//printf("%d", len);
	reverse(arr, low, high);
	
	
	printf("%s", arr);
	printf("\n");
	system("pause");
	return 0;

}