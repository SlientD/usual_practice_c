#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//断言
/////////////非递归：
int MyStrlen(char *a)
{
	int num = 0;
	while (a[num] != '\0')                        //if (*a == '\0')
	{
		num++;                                   //a++  指针加法 
	}
	return num;
}

/////////////递归：
int StrLen(char a[])                             //int StrLen(char *p)    
{
	if (*a == '\0')                             //if (*a == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + StrLen(a + 1);
	}

}
int main()
{
	char *arr = "abcdef";                         //char *p="abcdefe";    
	char arr1[] = "abcdef";
	//assert(arr != "abcdef");                          //断言  判断指针不能为。。。 debug 宏不是函数
	int s1 = StrLen(arr);                           // int s=StrLen(p); 
	int s2 = MyStrlen(arr);
	int s3 = strlen(arr);                        //没有 \0
	int s4 = sizeof(arr1);                       //有   \0
	printf("s1=%d,s2=%d\n", s1,s2);
	printf("s3=%d,s4=%d\n", s3, s4);
	system("pause");
	return 0;
}
