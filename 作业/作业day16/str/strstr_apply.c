#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//�����㷨      KMP
const char *My_Strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL&&strCharSet != NULL);
	const char* start = string;
	const char* st1 = NULL;
	const char* st2 = NULL;
	while (*start != '\0')
	{
		st1 = start;
		st2 = strCharSet;
		while (*st1 == *st2&&*st1 != '\0'&&*st2 != '\0')
		{
			st1++;
			st2++;
		}
		if (*st2 == '\0')
		{
			return start;
		}
		start++;

	}
	return NULL;


}

//logical error: ֻ����һ������ĸ��ͬ�ģ��Ϳ�ʼ�жϣ���ͬ�Ͳ����ٽ����������ˣ�
/*const char *My_Strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL&&strCharSet != NULL);
	if (strlen(string) < strlen(strCharSet)||*string=='\0')                      //���������ַ�������С����Ҫ�����ַ�������϶�û�У�����0
	{
		return NULL;
	}
	while (*string != *strCharSet&&*string!=0)                   //��ͷ��ĸһ����
	{
		string++;
		
	}
	const char* ret = string;                                          //��¼����λ��
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
*/

int main()
{
	char *a = "bbcdf";
	char *b = "xbbbcdef";
	//char* pos = strstr(b, a);
	char* pos = My_Strstr(b, a);
	printf("%s\n", pos);
	printf("%s\n", b);
	//if (strstr(b, a) == 0)
	if (My_Strstr(b,a) == 0)
		printf("b��û���ַ���a\n");
	else
		printf("b�����ַ���a\n");


	system("pause");
	return 0;
}