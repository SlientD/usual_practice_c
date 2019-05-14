#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int FindAllResult(int *arr,int len)
{
	int result = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		result ^= arr[i];
	}
	return result;
}
int FindPos(int n)
{
	int i=0;
	while (((n >> i) & 1) == 0)        //==1���ҵ��ˣ�ѭ��ֹͣ��==0����������1
	{
		i++;
	}
	return i;


}
void FindResult(int* px, int* py, int *arr, int len, int pos)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
		{
			*py = arr[i];
		}
	}


}
int main()
{
	int arr[] = { 2, 2, 5, 4, 7, 5 };
	int t;
	int pos = 0;
	int x = 0;
	int y = 0;
	int len = sizeof(arr) / sizeof(arr[0]);

	//1.��ȫ�����Ľ����
	 t= FindAllResult(arr,len);
	 //printf("ȫ������t=%d\n",t);

	 //2.��ȫ������������Ҫ����posλ�ɵõ�1���ڸ�λ���������ظ������Ϊ1�����ڸ�λ����������ͬ���ɴ˿��Է��顣
	 pos = FindPos(t);
	 //printf("����%dλ�ɵõ�\n", pos);

	 //3.���������������ƶ�posλΪ1�ķ�һ�飬0��Ϊ��һ�顣
	 FindResult(&x, &y, arr, len, pos);
	 printf("x=%d,y=%d\n", x,y);
	 




	 system("pause");
	 return 0;


}
