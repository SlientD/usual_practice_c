#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//void print(int num)
//{
//	int i = 31;
//	while (i >= 0)
//	{
//		printf("%d", (num >> i) & 1);
//		i--;
//	}
//}
void function(int num)
{
	int i;
	printf("奇数：");
	for (i = 30; i >=0; i -= 2)
	{
		printf("%d", (num >> i)&1);

	}
	printf("\n");
	printf("偶数：");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d",( num >> i)&1);

	}
	printf("\n");



}
int main()
{
	int number;
	int i = 0;
	int sum1 =0;
	int sum2 = 0;
	scanf("%d", &number);
	
	/*while (i < 16)
	{
		sum1 += ((number >> (2*i)) & 1)*(int)pow(2, i);
		sum2 += ((number >> (2*i + 1)) & 1)*(int)pow(2, i);
		i++;
	}
	printf("偶数位：");
	print(sum1);
	
	printf("\n奇数位：");
	print(sum2);*/
	function(number);
	printf("\n"); 
	system("pause");
	return 0;
}
