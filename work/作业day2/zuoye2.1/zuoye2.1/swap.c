#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*��λ����ȼӼ��˳�����
0000 1010 a
0001 0100 b
0001 1110  a^b  =a
0000 1010  a^b  =b
0001 0100  a^b  =a */ 

//int main()
//{
//	int m = 10, n = 20;
//	printf("%d,%d", m, n);
//	m = n-m;
//	n = n-m;
//	m = m+n;
//
//	printf("%d,%d", m, n);
//
//	return 0;
//}


//���Ż��������
//int main()
//{
//	int m = 10, n = 20;
//	printf("%d,%d", m, n);
//	m = m^n;
//	n = m^n;
//	m = m^n;
//
//	printf("%d,%d", m, n);
//  system("pause");
//	return 0;
//}


//�ֲ�����������
void swap(int m, int n){
	m = m^n;
	n = m^n;
	m = m^n;
}
int main()
{
	int m = 10, n = 20;
	printf("%d,%d\n", m, n);
	swap(m, n);
	printf("%d,%d", m, n);
	system("pause");
	return 0;
}

