#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int MC(int n, int k)
{
	if (k <= 1)
	{
		return n;
	}
	else{
		return    n*MC(n, k - 1);
	}
}
int main()
{
	int n, k,result;
	scanf("%d%d", &n, &k);
	result = MC(n, k);
	printf("%d", result);
	system("pause");
	return 0;
}