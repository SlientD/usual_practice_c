#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//�����ܱ�4���������ܱ�100���������꣬�ܱ�400����Ҳ������
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			printf("%d\n", year);
	}
	system("pause");

	return 0;
}