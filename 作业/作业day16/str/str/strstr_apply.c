#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char *My_Strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL&&strCharSet != NULL);
	if (strlen(string) < strlen(strCharSet))                      //���������ַ�������С����Ҫ�����ַ�������϶�û�У�����0
	{
		return NULL;
	}
	while (*string != *strCharSet&&*string!=0)                   //��ͷ��ĸһ����
	{
		string++;
		
	}
	char* ret = string;                                          //��¼����λ��
	if (*string==0)                                              //���������ַ������궼û��ͷ��ĸ����û�и��ַ���
	{
		return NULL;
	}
	
	while (*string == *strCharSet&&*strCharSet != 0)           //һ������ĸ�ж�
	{
		string++;
		strCharSet++;
	}
	if (*strCharSet==0)                                       //�����ˣ�����ĸȫ���ڱ����Ҵ���
		return ret;
	else
		return NULL;


}


int main()
{
	char *a = "abcd";
	char *b = "abcdef";
	//if (strstr(b, a) == 0)
	if (My_Strstr(b,a) == 0)
		printf("b��û���ַ���a\n");
	else
		printf("b�����ַ���a\n");


	system("pause");
	return 0;
}