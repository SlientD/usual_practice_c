#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 4


void FindNum(int arr[][N], int *px,int *py,int num){
	while (*px < N&&&*py >= 0)
	{
		if (arr[*px][*py] == num)
		{
			return;
		}
		else if (arr[*px][*py] > num)
		{
			(*py)--;
		}
		else if (arr[*px][*py] < num)
		{
			(*px)++;
		}
	}
	(*px) = -1;
	(*py) = -1;


}
int main()
{
	int arr[N][N]= { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	int px ,py;
	int num;
	scanf("%d", &num);
	px = 0;
	py = N - 1;
	FindNum(arr, &px,& py,num);
	if (px == -1)
	{
		printf("查无此数\n");
	}
	else{
		printf("%d,%d\n", px, py);
	}
	system("pause");
	return 0;
}