#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


void FIN(int arr[], int n)
{
	int i,t=0;
	int w=1;
	int x1=0, x2=0;
	for (i = 0; i < n; i++)
	{
		t ^= arr[i];                              //�ҳ������������
	}

	while (1)
	{
		if (((t >> 1) & 1) == 0)                 //�ҳ���Ҫ�ƶ�����λ�ſɵõ�������һ���Ĳ�ͬλ
		{
			w++;
			t = t >> 1;
		}
		
		else break;

	}
	for (i  = 0; i < n; i++)                           //���� ����ͬλΪ0�ķ�Ϊһ�飬����ͬλΪ1�ķ�Ϊһ��
	{      
		if (((arr[i] >> w) & 1) == 1)        
		{
			x1 ^= arr[i];
		}
		else
		{
			x2 ^= arr[i];
		}
                             
	}
	printf("%d,%d\n", x1,x2);
	
}



int main()
{

	
	int arr[10] = { 1, 1, 3, 3, 2, 5, 6, 5, 4, 6 };
	
	int len = sizeof(arr) / sizeof(arr[0]);
	FIN(arr, len);
	system("pause");
	return 0;
}