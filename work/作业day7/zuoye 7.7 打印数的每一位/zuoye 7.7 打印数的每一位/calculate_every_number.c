#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void print(int n)
{
	if (n >= 10)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);                    //��λ���λ��ӡ��������䷴һ�µ�λ���Ϊ��ӡ
	
}
int main()
{
	int number;
	scanf("%d", &number);
	print(number);

	system("pause");
	return 0;
}