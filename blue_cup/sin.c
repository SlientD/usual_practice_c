#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//设An=sin（1-sin(2+sin(3-sin(4+...sin(n))...)
//Sn=(...(A1+n)A2+N-1)A3+...+2)An+1
//输入n的值，求Sn
//例如：n=3时，((sin(1)+3)sin(1-sin(2)+2)sin(1-sin(2+sin(3)))+1
void PutA(int n, int k)
{
	if (n == k)
	{
		printf("sin(%d)", n);
	}
	else
	{
		printf("sin(%d",n);
		printf(n % 2 == 0 ? "+" : "-");
		PutA(n + 1, k);
		printf(")");
	}

}
void PutS(int n, int k)
{
	if (1 == n)
	{
		PutA(1, 1);
		printf("+%d", k - n);
	}
	else
	{
		printf("(");
		PutS(n - 1, k);
		printf(")");
		PutA(1, n);
		printf("+%d", k - n);
		

	}

}
int main()
{
	int N;
	scanf("%d", &N);
	PutS(N, N + 1);
	printf("\n");
	system("pause");
	return 0;


}