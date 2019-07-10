#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int DigitSum(int num)
{
	int sum;
	if (num >= 10)
	{
		return DigitSum(num / 10) + num % 10;                 //递归保护现场

		/*sum = num % 10;
		sum += DigitSum(num / 10);
		return sum;*/
	}
	else
		return num;
}
int main()
{
	int num,result;
	scanf("%d", &num);
	result = DigitSum(num);
	printf("%d\n", result);

	system("pause");
	return 0;
}