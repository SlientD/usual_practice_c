#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#if 0                   //���ÿ⺯��
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
void reverse1(char *arr, char* low,char* high)      //���廻
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
		while (*i != ' '&&*i != '\0')
			i++;
		reverse1(arr, t, i - 1);
		while (*i == ' ')     //���м��ж���ո񣬿��Կ������ո�
			i++;
		t = i;


	}
}
int main()
{
	char arr[100];

	gets(arr);
	int len = MYSTRLEN(arr);
	char *low = arr;
	char *high = len + arr - 1;
	printf("%d", len);
	//reverse(arr, low, high);
	reserve(arr);


	printf("%s", arr);
	printf("\n");
	system("pause");
	return 0;

}
#else     //ʹ�ÿ⺯��

void reserve(char* string)
{
	char* temp = string;
	char* res = (char *)malloc(strlen(string)+1);
	memset(res, 0, strlen(res));
	while (temp = strrchr(string, ' '))
	{
		strcat(res, temp+1);
		strcat(res, " ");                      //˫���ű�ʾ
		*temp = 0;                            //temp��ַ��string��ַһ����ȡ*�޸ģ�stringҲ���
	}
	strcat(res, string);
	strcpy(string, res);
	free(res);                                     //free����
	
}
int main()
{
	char arr[100];

	gets(arr);
	reserve(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;

}
#endif
