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
		sum += t;            //t��ǰһ�����ٳ���i�ͺã��ټӸ�sum������Ҫ�ظ���ֵ
	}


	printf("%d\n", sum);
	system("pause");


	return 0;
}