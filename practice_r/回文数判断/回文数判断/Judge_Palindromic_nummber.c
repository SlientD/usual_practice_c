#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Judge(char *arr, int len)
{
	int i;
	for (i = 0; i < len / 2; i++)
	{
		if (arr[i] != arr[len - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	////法一：将输入的数字转化为字符串
	//
	//char arr[100];
	//int len;
	//gets(arr);
	//len = strlen(arr);
	//if (Judge(arr, len))
	//{
	//	printf("yes\n");
	//}
	//else{
	//	printf("no\n");
	//}

	//法二：用结果判断
	int x,tmp,res=0;
	scanf("%d", &x);
	tmp = x;
	while(tmp){
		res = res * 10 + tmp % 10;
		tmp = tmp / 10;
	}
	if (x == res)
	{
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	//法三：对于大数字的，用栈来存储比较

	system("pause");
	return 0;
}