#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int a[],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}
void reverse(int *a, int n)                            //��ά int a[]ʵ������int *a;�����ʵ����Ԫ�ص�ַ 
{
	int low = 0;
	int high = n - 1;
	int temp;
	while (low < high)
	{
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		low++;
		high--;
	}



}
void empty(int a[], int n)
{
	int i;
	memset(a, 0, n*sizeof(a));                         //����sizeof ����һ���Ǹ�ֵ���ֽڴ�С����һ���������ֵ
	//for (i = 0; i < n; i++)
	//{
	//	a[i]=0;                                       //�ɸ�Ϊ*��arr+i��=0
	//}

}
//
//������ʲôʱ��ȷ����С�ģ�    ����
//ʲôʱ�򿪱��ڴ棿  ����
//�����￪�٣�  ջ     
//��࿪�ٶ��Ŀռ䣿  1M��2M    1M��1024 bit

int main()
{
	int i;
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr,len);
	printf("��ʼ����");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);      
	}
	
	printf("\n");	
	
	reverse(arr, len);
	printf("�����");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);                              //[] �Դ������� a[i]=*(arr+i);  i�ĵ�λ���ֽڣ�arrΪint�ͼ�4���ֽ�
	}
	printf("\n");


	empty(arr, len);
	printf("��պ�");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	system("pause");
	return 0;
}