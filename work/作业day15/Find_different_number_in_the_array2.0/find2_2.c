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
	while (((n >> i) & 1) == 0)        //==1就找到了，循环停止，==0继续往后找1
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

	//1.求全部异或的结果。
	 t= FindAllResult(arr,len);
	 //printf("全部异或后：t=%d\n",t);

	 //2.求全部异或后所得数要右移pos位可得到1。在该位上两个无重复数异或为1，即在该位上两个数不同，由此可以分组。
	 pos = FindPos(t);
	 //printf("右移%d位可得到\n", pos);

	 //3.分组找两个数，移动pos位为1的分一组，0分为另一组。
	 FindResult(&x, &y, arr, len, pos);
	 printf("x=%d,y=%d\n", x,y);
	 




	 system("pause");
	 return 0;


}
