#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����
/////////////�ǵݹ飺
int MyStrlen(char *a)
{
	int num = 0;
	while (a[num] != '\0')                        //if (*a == '\0')
	{
		num++;                                   //a++  ָ��ӷ� 
	}
	return num;
}

/////////////�ݹ飺
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
	//assert(arr != "abcdef");                          //����  �ж�ָ�벻��Ϊ������ debug �겻�Ǻ���
	int s1 = StrLen(arr);                           // int s=StrLen(p); 
	int s2 = MyStrlen(arr);
	int s3 = strlen(arr);                        //û�� \0
	int s4 = sizeof(arr1);                       //��   \0
	printf("s1=%d,s2=%d\n", s1,s2);
	printf("s3=%d,s4=%d\n", s3, s4);
	system("pause");
	return 0;
}
