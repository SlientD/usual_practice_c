#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�

int main()
{
	int money=40,number=40,count=40;
	while ( number > 1)
	{
		count += number / 2;
		number = number / 2 + number % 2;
		
	}
	printf("%d\n", count);

//20+10+5+2+1+1
//ʵ��Ϊ2*money-1����Ϊÿ�ο�ƿ����Ϊ��һ�ε���Ŀ/2��
	system("pause");
	return 0;

}