#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ˮ�ɻ�����ֻ��3λ������λ�����η�
//������1������λ�� 2�������λ���� 3�������
int main(){
	int i,t,number,c;
	int a[10];
	int sum;
	
	
	for (number = 1; number < 999; number++)
	{//��λ��������λ����
		sum = 0;
		t = 0;
		i = number;
		while (i)
		{
			
				a[t] = i % 10; //0���λ��ʼ
				t++;           //tλ��		
				i = i / 10;    //�ı�ֵ
			
		}
		
	//���
		c = t;
		while (t--)
			sum += pow(a[t], c);

	//�η��Ӻ��ж�
		if (sum == number)
			printf("%d\n", number);

	}
	
	system("pause");

	return 0;
}