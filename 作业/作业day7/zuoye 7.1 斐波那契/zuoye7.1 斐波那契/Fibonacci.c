#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
�ݹ飺
����ֹ����
�Լ����Լ�
*/

int count = 0;                          //�����˼���F(1)
int F(int num)
{

	if (num == 1 || num == 2)
	{
		count++;
		return 1;
		
	}
	else
	{
		return (F(num - 1) + F(num - 2));
	}
}
int main()
{
	int first, second, third;
	int number;
	scanf("%d", &number);
	first = 1;
	second = 1;
	third = F(number);
	//if (number <=2)                                //����д������ٶȿ죬Ч�ʸ�
	//{
	//	third = second;
	//}
	//else
	//{
	//	while (number > 2)
	//	{
	//		third = second + first;
	//		second = third;
	//		first = second;
	//		number--;
	//	}
	//}
	printf("count=%d ", count);
	printf("%d ", third);
	system("pause");
	return 0;
}