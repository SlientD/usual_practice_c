#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	int m, n;
	int i, temp;
	int sum=0;
	scanf("%d%d", &m, &n);   //m=2��n=4
	temp = m;
	for (i = 0; i<n; i++)
	{
		temp += temp*10;   // �����2+22+222+2222   ->ϵ������
		sum += temp;             //      ->�ܺ�   �ܶ���붼����д�����ָ�ʽ��ֻ����ϵ��������Ҫ������ʵ�ֲ�ͬ����
	}


	system("pause");
	return 0;

}