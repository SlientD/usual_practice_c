#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int t)
{
	int j;
	for (j = 2; j <= sqrt(t); j++)
	{
		if (t%j == 0)
			return 0;
	}
	return 1;

}
int main()
{ 
	int i;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)    //ÅÐ¶ÏËØÊý
		{
 			printf("%-6d", i);
		}


	}

	system("pause");
	return 0;
}