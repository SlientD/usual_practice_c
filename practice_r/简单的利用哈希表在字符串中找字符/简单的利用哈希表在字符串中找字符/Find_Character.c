#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//��һ�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������b��Ҫ��ʱ�临�Ӷ�ΪO��n��
//˼·1��O(N^2)��������ͷ��β������ÿ���ַ����ٴӺ���ǰ��ʼ�������ң�������һ����ͬ�ģ���˵�����ַ����ظ���break����ֱ������һ���ַ��Ӻ���ǰ��ֻ����һ�����������ǵ�һ������һ�ε��ַ�
//˼·2��O(N)����������һ��256��С�����飬��ʼ��Ϊ0��ÿ���ַ�ascii ��Ӧ�±�Ŀռ����Ÿ��ַ����ֵĴ���������һ�����飬����ֵΪ��һ��ֵ1�ģ������±���Ϊ���������ַ���ascii ֵ

char FindCharacter1(char *str)
{
	//assert(str, NULL);
	int tmp[256] = { 0 };       //Ϊʲô��256����Ϊchar��ռ8������λ���ɱ�ʾ2^8���ַ�
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

//�������һ���ַ������ҵ���һ���ظ����ֵ��ַ������磺"qywyer23tdd",���y
//˼·������һ��256��С�����飬�÷����ϣ���һ�����ǣ���Ӧasc�±��ֵ��һ֮ǰ���ж�һ�£������0�ͼ�һ�������1��ô���ַ����ǵ�һ���ظ����ֵ��ַ���return�ͺá�
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