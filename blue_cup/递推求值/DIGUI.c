#define _CRT_SECURE_NO_WARNINGS 1
//F(n, 1)=F(n-1, 2) + 2F(n-3, 1) + 5,
//F(n, 2) = F(n - 1, 1) + 3F(n - 3, 1) + 2F(n - 3, 2) + 3.
//³õÊ¼ÖµÎª£ºF(1, 1) = 2, F(1, 2) = 3, F(2, 1) = 1, F(2, 2) = 4, F(3, 1) = 6, F(3, 2) = 5
#include <stdio.h>
#include <stdlib.h>
int Recursion(int arr[][2],int n,int k)
{
	if (n <= 3)
	{
		return arr[n - 1][k];
	}
	else
	{
		if (0 == k)
		{
			return Recursion(arr, n - 1, k+1) + 2 * Recursion(arr, n - 3, k) + 5;
		}
		else
		{
			return Recursion(arr, n - 1, k - 1) + 3 * Recursion(arr, n - 3, k-1)+2 * Recursion(arr, n - 3, k) + 3;
		}
		
	}


}
int main()
{
	int arr[3][2] = { { 2, 3 }, { 1, 4 }, { 6, 5 } };
	int n,F1,F2;
	scanf("%d", &n);
	F1=Recursion(arr,n,0);
	F2 = Recursion(arr, n, 1);

	printf("F1=%d\n", F1);
	printf("F2=%d\n", F2);

	system("pause");
	return 0;
}