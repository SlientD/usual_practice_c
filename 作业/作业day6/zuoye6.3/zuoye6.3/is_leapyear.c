#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int Is_prime(int y)
{
	int j;
	for (j = 2; j <= sqrt(y); j++)
	{
		if (0 == y%j)
		{
			return 0;
		}
	}
	return 1;
	
}


int main()
{
	int i=100;
	for (; i < 300; i++)
	{
		if (1 == Is_prime(i))
		{
			printf("%d ", i);              //在外面打印
		}

	}
	system("pause");
	return 0;
}
//void judge(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
//		printf("该年是闰年\n");
//	else printf("该不是闰年\n");
//}
//
//
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	judge(year);
//	system("pause");
//	return 0;
//}

