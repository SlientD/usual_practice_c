#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a, b,c1;
	double c;
	for (a = 3; a <= 300; a++)
	{
		for (b = a+1; b <= 800; b++)
		{
			c = sqrt(a*a + b*b);
			c1 =(int) c;
			if ((a + b + c) <= 1000 && c == (double)c1)
			{
				printf("%-3d,%-3d,%-3d\n", a, b, c1);
			}
		}
	}
	

	system("pause");
	return 0;


}