#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 3
void print_arr(int *arr)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{

			printf("%d ", arr[i*N + j]);         //i行*列数+j列
		}
		printf("\n");
	}

}


void find(int arr[][N],int *px,int *py,int num )
{
	while (*px < N && *py >= 0)
	{
		if (arr[*px][*py] == num)
		{
			return ;
		}
		else if (arr[*px][*py] > num)
		{
			(*py)--;
		}
		else{
			(*px)++;
		}
	}
	*px = -1;
	*py = -1;
	return ;


}


int main()
{

	int a[N][N] = { { 1, 2, 3 }, { 2, 3, 4 }, { 7, 8, 9 } };
	
	int x = 0;
	int y = N-1;
	int num;
	print_arr((int *)a);                  //强转为一维数组
	printf("寻找的数是：");
	scanf("%d", &num);
	find(a, &x, &y,num);
	if (x != -1 && y != -1)
	{
		printf("找到了，坐标是：%d,%d\n", x, y);
	}
	else
	{
		printf("没有该数");
	}

	system("pause");
	return 0;
}





//y从0开始找会出问题
//int x, y;
//int Findx(int a[][3],int num)
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		if (a[0][i]>num)
//		{
//			break;
//
//		}
//	}
//	return i-1;
//}
//
//int Findy(int a[][3], int num)
//{
//	int j;
//	for (j = 0; j < N; j++)
//	{
//		if (a[j][y] == num)
//		{
//			return j;
//		}
//		if (num<a[j][y])
//		{
//			break;
//		}
//	}
//	return -1;
//
//}
//
//int main()
//{
//	int a[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 7, 8, 9 } };
//	printf("请输入要查找的数：");
//	int number;
//	scanf("%d", &number);
//	
//	print_arr((int *)a, 3, 3);
//	y = Findx(a,number);
//	x = Findy(a, number);
//	if (x == -1)
//	{
//		printf("none number");
//	}
//	else
//	{
//		printf("the number is exist");
//	}
//	system("pause");
//	return 0;
//}

	

//1 2 3
//2 4 5
//7 8 9
//找7
