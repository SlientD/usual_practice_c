#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��Ŀ�����������ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ��������е��ַ������磬����"They are students"��"aeiou"����ɾ��֮��ĵ�һ���ַ�����Ϊ"Thy r stdnts"
//˼·���������ڲ�������Ԫ����ĸ���ͽ��������ĸ��ǰ���ǡ���һ��step����ʾ�������Ҫ��ǰ�߶��ٸ���������λ�á�ÿ����һ���ڶ��ַ����е���ĸ��i����step�ͼ�һ����˼�Ǹ��������Ԫ��Ӧ����i+step�е�Ԫ��

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
		while (JudgeCharacter(str[i+step], dstr))   //�ж���һ��Ҫ������ĸ�ǲ��Ǹ�dstr�ַ����еģ������ǵڶ����ַ����е���ĸ��stepҪ��һ���ҵ���step����һ��Ԫ�������ǵ�ǰλ�õ�Ԫ��
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