#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 3
int Find_Number(int *a)
{
	int i,num=0;
	for (i = 0; i < N; i++)
	{
		num ^= *(a + i);
	}
	return num;

}
int main()
{
	int a[N];
	int number,i;
	printf("请输入%d个数，其中只有一个无重复数:", N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	number=Find_Number(a);
	printf("%d\n", number);


	system("pause");
	return 0;
}