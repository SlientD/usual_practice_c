#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CompressStr(char *str)
{
	int i=0,count;
	int pos=0;                         //记录要填的是第几个位置
	while (*(str+i)){                  //i是原来字符串中要判断的位置
		count = 1;
		while(*(str + i) == *(str + i + count))
		{
			count++;
		}
		if (count > 1)
		{
			*(str + pos) = '0' + count;
			*(str + pos + 1) = *(str + i + count-1);
			pos += 2;
		}
		else{
			*(str + pos) = *(str + i);
			pos++;
		}
		i = i + count;
	}
	*(str + pos) = '\0';

}
int main(){
	char str[] = "aabbbssbggrtrrrrtrrrt";
	CompressStr(str);
	printf("%s", str);

	system("pause");
	return 0;
}