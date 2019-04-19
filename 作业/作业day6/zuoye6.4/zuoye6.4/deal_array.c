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
void reverse(int *a, int n)                            //降维 int a[]实际上是int *a;存的是实参首元素地址 
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
	memset(a, 0, n*sizeof(a));                         //后面sizeof 的哪一项是赋值的字节大小，是一个具体的数值
	//for (i = 0; i < n; i++)
	//{
	//	a[i]=0;                                       //可改为*（arr+i）=0
	//}

}
//
//数组是什么时候确定大小的？    编译
//什么时候开辟内存？  运行
//在哪里开辟？  栈     
//最多开辟多大的空间？  1M或2M    1M是1024 bit

int main()
{
	int i;
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr,len);
	printf("初始化后：");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);      
	}
	
	printf("\n");	
	
	reverse(arr, len);
	printf("逆序后：");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);                              //[] 自带解引用 a[i]=*(arr+i);  i的单位是字节，arr为int型加4个字节
	}
	printf("\n");


	empty(arr, len);
	printf("清空后：");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	
	system("pause");
	return 0;
}