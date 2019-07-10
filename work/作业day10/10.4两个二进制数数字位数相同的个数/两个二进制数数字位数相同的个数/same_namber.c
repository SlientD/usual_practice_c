#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1, num2,num;
	
	int count = 0;
	scanf("%d%d", &num1, &num2);
	num = num1^num2;
	
	
		while (num)
		{
			num=num&(num-1);
			count++;
		}
	
	/*while (i < 32)
	{
		if (0 == ((num1 >> i & 1) ^ (num2 >> i & 1)))
		{
			count++;
		}
		i++;
	}*/
	printf("%d\n", count);

	system("pause");
	return;
}