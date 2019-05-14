#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//朴素算法      KMP
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

//logical error: 只碰到一个首字母相同的，就开始判断，不同就不会再接着往下找了！
/*const char *My_Strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL&&strCharSet != NULL);
	if (strlen(string) < strlen(strCharSet)||*string=='\0')                      //若被查找字符串长度小于需要查找字符串，则肯定没有，返回0
	{
		return NULL;
	}
	while (*string != *strCharSet&&*string!=0)                   //找头字母一样的
	{
		string++;
		
	}
	const char* ret = string;                                          //记录所在位置
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
		printf("b中没有字符串a\n");
	else
		printf("b中有字符串a\n");


	system("pause");
	return 0;
}