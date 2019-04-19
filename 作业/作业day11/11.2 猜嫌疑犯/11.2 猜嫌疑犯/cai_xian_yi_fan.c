#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;	
	for (x = 1; x <= 4; x++)
	{
		if ((x != 1) + (3 == x) + (4 == x) + (x != 4) == 3)
		{

			printf("%c ÊÇÐ×ÊÖ\n", x + 64);
		}
	}
	system("pause");
	return 0;
}