#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main()
{
	int n;
	int line, count;
	int pose;
	scanf("%d", &n);
	count = 0;
	line = 1;
	while (count + line < n)
	{
		count = count + line;
		line++;
	}
	pose = n - count;
	printf("%d/%d\n", pose, line - pose + 1);



	system("pause");
	return 0;
}