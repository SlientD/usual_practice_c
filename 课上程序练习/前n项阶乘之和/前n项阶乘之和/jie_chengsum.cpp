#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, i,t;
	int sum = 0;
	t = 1;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		t = t*i;
		sum += t;            //t在前一项上再乘于i就好，再加给sum，不需要重复赋值
	}


	printf("%d\n", sum);
	system("pause");


	return 0;
}