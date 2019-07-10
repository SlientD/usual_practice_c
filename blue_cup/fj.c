#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//FJ 数列：A1=A;  A2=A B A    A3=ABA C ABA      A4=ABACABA D ABACABA  
//典型的递归。。。。，，出口就是A
void Out(int n)
{
	if (1 == n)
	{
		printf("A");
	}
	else{
		Out(n - 1);
		printf("%c", 'A' + n-1);
		Out(n - 1);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
    
	Out(n);

	system("pause");
	return 0;
}