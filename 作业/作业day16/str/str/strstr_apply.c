#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char *My_Strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL&&strCharSet != NULL);
	if (strlen(string) < strlen(strCharSet))                      //若被查找字符串长度小于需要查找字符串，则肯定没有，返回0
	{
		return NULL;
	}
	while (*string != *strCharSet&&*string!=0)                   //找头字母一样的
	{
		string++;
		
	}
	char* ret = string;                                          //记录所在位置
	if (*string==0)                                              //若被查找字符串找完都没有头字母，则没有该字符串
	{
		return NULL;
	}
	
	while (*string == *strCharSet&&*strCharSet != 0)           //一个个字母判断
	{
		string++;
		strCharSet++;
	}
	if (*strCharSet==0)                                       //找完了，则字母全都在被查找串里
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
		printf("b中没有字符串a\n");
	else
		printf("b中有字符串a\n");


	system("pause");
	return 0;
}