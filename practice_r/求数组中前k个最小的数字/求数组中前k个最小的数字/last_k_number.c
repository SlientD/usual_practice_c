#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 10


//����һ�����ÿ�����������ԣ���һ�ο��ź󣬷ֽ�ֵ�����С�ڸ÷ֽ�ֵ���ұߴ��ڸ÷ֽ�ֵ��
//��ĳ�ֽ�ֵ���±���k-1����ô�ֽ�㼰�ֽ��ǰ�������Ǹ���������С��k������
//��ˣ�������ͱ�����ҷֽ�ֵ�±�Ϊk-1��λ�ã������� ��

int QuckSortOne(int *a,int right,int left)        //����ÿһ�ηֽ����±�
{
	
	int x = a[right];
	
	
	while (right < left)
	{
		while (x<a[left] && right < left)
		{
			left--;
		}
		if (right < left)
		{
			a[right] = a[left];
		}

		while (x>=a[right] && right < left)
		{
			right++;
		}
		if (right < left)
		{
			a[left] = a[right];
		}
		
	}
	a[left] = x;
	return left;

}


void LastK(int *a,int k)              //�ҷֽ��ǡ��������߼�����һ����k��ֵ ���Ҹ�k��ֵ����������Сk����
{
	int start = 0;
	int end = N-1;
	int result;
	do{

		result = QuckSortOne(a,start,end);
		if (result > k)
		{
			end = result-1;
		}
		if (result < k)
		{
			start = result+1;
		}
		
	} while (result != k-1);      //Ϊʲô�˴�Ϊk-1����Ϊresult�Ƿֽ�ֵ���±꣬����ǰN ��k=N������С��ʱ�������ֵ���±���N-1�����Է�ֹԽ�磬��result����K-1�Ƚ�

}

int main()
{
	int a[N] = { 1, 9, 2, 5, 4, 7, 8, 3, 10, 6 };
	int k,i;

	scanf("%d", &k);
	if (k > N)
	{
		printf("k is error\n");
	}
	else{
		LastK(a, k);
		for (i = 0; i < k; i++){
			printf("%d ", a[i]);
		}
	}

	system("pause");
	return 0;
}