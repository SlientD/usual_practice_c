#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//题目：删除字符串首尾的空格，中间的连续空格只留一个，原来字符串顺序不变，如："*****as*****adjj*ji**"变为"as*adjj*ji"(*为空格)

//思路：与之前写的在一个字符串中删除对应字母的思路一样，不过中间出现的连续空格要保留一个空格，那对应作出相应改变：遇见中间空格时，算出经过空格的step后
//让步数减一即可。（每遇见一串空格次减一），另还要找确定是中间的空格字符串的判断条件即开始数这空格字符串时所在位置不是0，（排除开头）step加上后没有遇上‘\0’(排除结尾)


void DeleteSpace(char *str)
{
	int i;
	int step=0;
	int flag = 0;
	int tmp;
	for (i = 0; *(str + i);i++){

		tmp = step;
		if (*(str + i + step) == ' '){
			while (*(str + i + step) == ' ')
			{

				step++;
			}
			if (i != 0 && *(str + i + step))
			{
				step--;
			}
			
		}
		*(str + i) = *(str + i + step);
	}
	
	
}
int main()
{
	char str[] = "    ab cc  x   ";
	DeleteSpace(str);
	printf("%s", str);

	system("pause");
	return 0;
}