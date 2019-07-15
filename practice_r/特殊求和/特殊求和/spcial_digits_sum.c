#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	int m, n;
	int i, temp;
	int sum=0;
	scanf("%d%d", &m, &n);   //m=2，n=4
	temp = m;
	for (i = 0; i<n; i++)
	{
		temp += temp*10;   // 输出：2+22+222+2222   ->系数变量
		sum += temp;             //      ->总和   很多代码都可以写成这种格式，只不过系数变量需要更改以实现不同需求。
	}


	system("pause");
	return 0;

}