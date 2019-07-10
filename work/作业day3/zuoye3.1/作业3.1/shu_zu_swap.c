#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 10
//
//void show(int * a[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//		printf("%d",a[i]);    //*（a+i)   指针的加法
//	printf("/n");
//
//
//
//
//}
void swap(int* i, int* j)
{
	*i = *i^*j;
	*j = *i^*j;
	*i = *i^*j;
}
int main()
{

	int A[N],B[N];
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d",& A[i]);
	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
	}
	printf("\n");
	

	for (i = 0; i < N; i++)
		swap(&A[i], &B[i]);
	for (i = 0; i < N; i++)
	{
		printf("%d ",A[i]);

	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", B[i]);

	}
	system("pause");





}