#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[20];
	char b[20][10] = { "ling ", "yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu " };
	char c[20][10] = { "", "", "shi ", "bai ", "qian ", "wan ", "shi ", "bai ", "qian ", "yi ", "shi " };
	gets(a);
	int len = strlen(a);
	int i,j,k; 
	
	for (i = 0; i < len; i++)
	{
		j = a[i] - 48;
		k = i;
		while (len - k - 1)
		{
			if (a[k + 1] != 48)
			{
				break;
			}
			k++;
		}
		if (0 == j)
		{
			if (a[i + 1] != 48 && i < (len - 1))
			{
				printf("%s", b[j]);
			}
		}


		else if (0 == (len - k - 1))
		{
			if (j == 1 && ((len - i) == 2 || (len - i) == 6 || (len - i) == 10))
			{
				printf("%s", c[len - i]);
			}
			else
				printf("%s%s", b[j], c[len - i]);
		
			if ((len - i) > 5 && (len - i) <= 9)
			{
				printf("wan");
			}
			if ((len - i) > 9)
			{
				printf("yi");
			}
		}
		else if (((len - i) == 2 || (len - i) == 6 || (len - i) == 10) && j == 1)
		{
			printf("%s", c[len - i]);
		}
		else if (a[i - 1] == 48 && j == 1)
		{
			printf("%s", b[j]);
		}
		else
		{
			printf("%s%s", b[j], c[len - i]);
		}



	}

	printf("\n");
	system("pause");
	return 0;
}