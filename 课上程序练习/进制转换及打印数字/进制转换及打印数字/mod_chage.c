#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//递归方式实现打印一个整数的每一位



int print(int n,int m)
{
	if (n < m)
	{
		putchar("0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"[n]);
		return 0;
	}

	print(n / m,m);
	putchar("0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"[n%m]);  //十六进制表示，没必要去定义一个数组
	return 0;
}
int main()
{
	int n,m;
	scanf("%d%d", &n,&m);
	
	print(n, m);



	system("pause");
	return 0;
}

