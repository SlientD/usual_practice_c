#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CharIstead(char* s, char x, char* s1)
{
	int num=0;
	int len = strlen(s);
	int len1 = strlen(s1);
	int len_t;
	int i=0, j,k;

	while (s[i])
	{
		if (s[i] == ' ')
		{
			num++;
		}
		i++;

	}
	len_t = len + strlen(s1)*num-num;
	i = len-1, j = len_t-1;
	while (i >= 0)
	{
		if (s[i] == x)
		{
			k = strlen(s1) - 1;
			while (k>=0)
			{
				s[j] = s1[k];
				k--;
				j--;
			}
			i--;
		}
		else{
			s[j] = s[i];
			j--;
			i--;
		}

	}
	
	

}
int main(){
	//char* s = "LOPOJJJOOO";      //在字符常量区，不可以随意修改！！
	char s[100] = "LOPOJJJOOO  ";
	CharIstead(s, ' ', "%20");
	printf("%s", s);
	system("pause");
	return 0;




}