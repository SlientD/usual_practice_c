#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//·ÇµÝ¹é
int FunPow(int x, int y)
{
	int res=1;
	
	if (y == 0)
	{
		return 1;
	}
	while (y--)
	{
		res *= x;
	}
	return  res;
}
//µÝ¹é
int FunPow1(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	return x*FunPow1(x, y - 1);
	
}


int main()
{
	int x, y,res;
	scanf("%d%d", &x, &y);
	res = FunPow1(x, y);
	printf("%d\n", res);

	system("pause");
	return 0;
}