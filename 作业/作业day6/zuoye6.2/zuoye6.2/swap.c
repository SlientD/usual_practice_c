#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//���ִ����
//void swap1(int *a, int *b)   //�������ǵ�ַ  ֻ����aָ��j��a������j�ĵ�ַ����bָ��i��
//{
//	int *temp;               //Ұָ��   û�г�ʼ��
//	temp = a;
//	a = b;
//	b = temp;
//}
//


//void swap(int a, int b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}


void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a = *b;
	*b = temp;
}

int main()
{
	int i=1, j=2;
	swap(&i, &j);
	printf("i=%d,j=%d", i, j);


	system("pause");
	return 0;
}