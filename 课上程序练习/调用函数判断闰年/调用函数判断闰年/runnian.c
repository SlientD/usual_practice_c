#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int is_runnian(int i)
{
	return (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
	//if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	//	return 1;


	 return 0;
}
int main()
{
	int i;
	for (i = 1000; i <= 2000; i=i+4)
	{
		if (is_runnian(i) == 1)
			printf("%-5d", i);
	}



	system("pause");
	return 0;
}