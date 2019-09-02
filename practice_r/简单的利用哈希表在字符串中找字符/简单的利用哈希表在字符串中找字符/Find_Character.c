#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//题一：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出b，要求时间复杂度为O（n）
//思路1：O(N^2)方法：从头到尾遍历，每个字符都再从后向前开始都向后查找，若遇见一个相同的，则说明该字符有重复，break掉，直到遇见一个字符从后往前找只有他一个，则他就是第一个出现一次的字符
//思路2：O(N)方法：建立一个256大小的数组，初始化为0，每个字符ascii 对应下标的空间里存放该字符出现的次数，遍历一遍数组，遇见值为第一个值1的，数组下标则为满足条件字符的ascii 值

char FindCharacter1(char *str)
{
	//assert(str, NULL);
	int tmp[256] = { 0 };       //为什么是256？因为char型占8个比特位，可表示2^8个字符
	int i;
	while (*str)
	{
		tmp[*str]++;
		str++;
	}
	for (i = 0; i < 256; i++)
	{
		if (tmp[i] == 1)
		{

			return (char)i;
		}
	}
	return -1;
}

//题二：在一个字符串中找到第一次重复出现的字符，例如："qywyer23tdd",输出y
//思路：建立一个256大小的数组，用法如上，不一样的是，对应asc下标的值加一之前，判断一下，如果是0就加一，如果是1那么该字符就是第一次重复出现的字符，return就好。
char FindCharacter2(char *str)
{
	//assert(str, NULL);
	int tmp[256] = { 0 };       
	while (*str)
	{
		if (tmp[*str] == 0)
		{
			tmp[*str]++;
			str++;
		}
		else if (tmp[*str] == 1)
		{
			return *str;
		}
	}
	
}

int main()
{
	char *str = "abaccdeff";
	char k;
	k = FindCharacter2(str);
	printf("The character is %c.\n", k);
	system("pause");
	return 0;
}