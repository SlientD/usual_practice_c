#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void *My_Memmove(char* destination,const char* source, int num)
{
	char *des = destination;
	char *src = source;
	if (destination > source && (source + num) > destination)
	{
		des = des + num-1;
		src = src + num-1;
		while (num--)
		{
			*des = *src;
			des--;
			src--;
		}
	}
	else{
		while (num--)
		{
			*des = *src;
			des++;
			src++;
		}
	}
	return destination;

	

}
int main()
{
	char a[] = "abcdef";
	//char b[] = "abcdef";
	My_Memmove(a+2, a, 3);
	printf("My_Memmove后：%s\n", a);
	//memmove(a+2, a, 3);                  
	//printf("memmove后：%s\n", a);
	//memcpy(b + 2, b, 3);                    //与memmove一样
	//printf("memcpy后：%s\n", b);



	system("pause");
	return 0;
}