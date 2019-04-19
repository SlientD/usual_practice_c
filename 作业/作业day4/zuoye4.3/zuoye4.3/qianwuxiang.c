#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,i,sum;
	sum = 0; 
	scanf("%d", &a);
	b = a;
	for (i = 1; i <= 5; i++)
	{
		sum += a;
		a = a * 10 + b;
		
	}
	printf("%d\n", sum);

	system("pause");

	return 0;
}