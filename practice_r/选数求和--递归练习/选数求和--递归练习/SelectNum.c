#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int n;
int count=1;
int arr[SIZE];

//�ֽ��n�������⣬��m���������Կ�����һ���Ӻ���m-1���� ����һ����������Ҫ�Ӽ�������tol�Ǽ���ǰn����ֵ�Ƕ����ˣ�pos��Ҫ�ӵĵ�i�������Դ�����ĵڼ���λ�ÿ�ʼ��
void sum(int m,int tol,int pos)          //m�ǻ��м���Ҫ�ӣ�tol�����ӵ�ֵ�����������pos�Ǳ��μ����Ŀ��Դ��ĸ�λ�ÿ�ʼ��
{
	int i;
	if (m <= 0)
	{
		printf("sum%d:%d\n", count, tol);
		return;
	}
	for (i = pos; i < n; i++)           //��һ�������Դ�����ĵ�һ��λ�ÿ�ʼ�ӣ�������ĩβ������һ�飩���ڶ��������Դ�����ĵڶ���λ�ÿ�ʼ�ӣ�����ĩβ������һ�飩
	{
		sum( m - 1, tol + arr[i], i + 1);   //�ݹ�ʱ����һ������λ��һ������������λ�õ���һ���ռ俪ʼ������ԣ�pos=i+1��pos����һ������ʼ�ӵ�λ�ã�i���������λ��
	}                                        
	       
	
}



int main()
{
	int  m;
	int i;
	
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sum( m,0,0);



	system("pause");
	return 0;
}