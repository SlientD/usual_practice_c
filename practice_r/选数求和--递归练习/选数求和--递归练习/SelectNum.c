#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int n;
int count=1;
int arr[SIZE];

//分解成n个子问题，加m个数，可以看做第一个加后面m-1个数 ，第一个参数传还要加几个数，tol是加完前n个数值是多少了，pos是要加的第i个数可以从数组的第几个位置开始加
void sum(int m,int tol,int pos)          //m是还有几个要加，tol是最后加的值，方便输出，pos是本次加数的可以从哪个位置开始加
{
	int i;
	if (m <= 0)
	{
		printf("sum%d:%d\n", count, tol);
		return;
	}
	for (i = pos; i < n; i++)           //第一个数可以从数组的第一个位置开始加（到数组末尾都试了一遍），第二个数可以从数组的第二个位置开始加，（到末尾都试了一遍）
	{
		sum( m - 1, tol + arr[i], i + 1);   //递归时：下一个数的位置一定从数组的这个位置的下一个空间开始，向后试，pos=i+1；pos是下一个数开始加的位置，i是这个数的位置
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