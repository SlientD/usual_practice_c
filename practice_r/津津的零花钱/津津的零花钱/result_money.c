#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int ,result,buget,h,total;
	int month=1;
	result = 0;
	total = 0;
	while (month <= 12)
	{
		scanf("%d", &buget);
		result = 300 + result - buget;
		if (result < 0)
		{
			printf("在第-%d月没钱了\n", month);
			break;
		}
		h = result / 100;
		total += h;
		result = result - h * 100;
		month++;
	}
	if (month>12)
	{
		printf("最后共有%f钱",(total * 100*1.2 + result));
	}



	System("pause");
	return 0;


}