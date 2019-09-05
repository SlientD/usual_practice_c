#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//题目：输入两个字符串，从第一个字符串中删除第二个字符串中所有的字符。例如，输入"They are students"和"aeiou"，则删除之后的第一个字符串变为"Thy r stdnts"
//思路：在数组内部，碰到元音字母，就将后面的字母往前覆盖。用一个step，表示后面的数要往前走多少个到达最终位置。每遇见一个第二字符串中的字母（i），step就加一，意思是覆盖这里的元素应该是i+step中的元素

int JudgeCharacter(char x, char *dstr){
	int i;
	for (i = 0; dstr[i]; i++)
	{
		if (x == dstr[i])
		{
			return 1;
		}
	}
	return 0;

}

void DeleteCharacter(char *str, char *dstr){
	int i,step=0;
	for (i = 0; str[i]; i++)
	{
		while (JudgeCharacter(str[i+step], dstr))   //判断下一个要填到这的字母是不是个dstr字符串中的，若还是第二个字符串中的字母，step要加一，找到加step的下一个元素来覆盖当前位置的元素
		{
			step++;
		}
		
		str[i] = str[i + step];
	}

}

int main()
{
	char str[] = "They are students.";
	char dstr[] = "aeiou";
	DeleteCharacter(str, dstr);
	printf("%s", str);


	system("pause");
	return 0;

}