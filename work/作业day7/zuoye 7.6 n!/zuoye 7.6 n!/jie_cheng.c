#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//µÝ¹é
int fx1(int n)
{
	if (1 == n)
	{
		return 1;
	}
	else{ 
		return n*fx1(n - 1); 
	}
}
//·ÇµÝ¹é
int fx2(int num)
{
	int sum = 1;
	for (num; num > 0; num--)
	{
		sum *= num;
	}
	return sum;
}
int main()
{
	int num,result1,result2;
	scanf("%d", &num);
	result1 = fx1(num);
	result2 = fx2(num);
	printf("result1=%d,result2=%d\n", result1,result2);

	system("pause");
	return 0;
}




