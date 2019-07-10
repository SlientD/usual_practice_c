#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch;
	     
	while ((ch = getchar()) != EOF)  //getchar 的返回值为什么是int型？         EOF 是一个宏=-1 ctrl+z结束程序     死循环ctrl+c结束死循环
	{
		;
		if (ch >= 'A' && ch <= 'Z')       //A->65
			printf("%c", ch + 32);

		if (ch >= 'a' && ch <= 'z')      //a->97
			printf("%c", ch - 32);
		//if (ch >= '0' && ch <= '9')       //'0'->48

	}
	

	system("pause");
	return 0;
}