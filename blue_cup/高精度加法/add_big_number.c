#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[1000], b[1000];
	int c[1000];
	gets(a);
	gets(b);
	int i,d=0;
	int lena = strlen(a);
	int lenb = strlen(b);
	int lenc = lena >= lenb ? lena : lenb;

	for (i = 0; i < lenc; i++)
	{
		if (i < lena&&i < lenb)
		{
			c[i] = a[lena - i - 1] + b[lenb - i - 1]+d-96;
			d = c[i] / 10;
			c[i] = c[i] % 10;
		}
		else if (i < lena)
		{
			c[i] = a[lena - i - 1] + d-48;
			d = c[i] / 10;
			c[i] = c[i] % 10;
		}
		else if (i < lenb)
		{
			c[i] = b[lenb - i - 1] + d-48;
			d = c[i] / 10;
			c[i] = c[i] % 10;
		}
			
	}
	if (d)
	{
		printf("%d", d);
	}
	for (i = lenc - 1; i >= 0; i--)
	{
		printf("%d", c[i]);
	}

	printf("\n");

	system("pause");
	return 0;
}