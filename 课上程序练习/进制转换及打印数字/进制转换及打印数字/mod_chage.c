#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ



int print(int n,int m)
{
	if (n < m)
	{
		putchar("0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"[n]);
		return 0;
	}

	print(n / m,m);
	putchar("0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"[n%m]);  //ʮ�����Ʊ�ʾ��û��Ҫȥ����һ������
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

