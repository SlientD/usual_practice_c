#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//递归
void reseve(char *str)

{
	int len = strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str+1) > 1)
	{
		reseve(str+1);
	}
	*(str+len-1)= tmp;                 //str之前的的位置，len之后的位置重复了str指向位置
}



//只递不归
//void reseve(char *str,int low,int high)
//
//{
//	if (low < high)
//	{
//		str[low] = str[high] ^ str[low];
//		str[high] = str[high] ^ str[low];
//		str[low] = str[high] ^ str[low];
//		reseve(str, low + 1, high - 1);
//	}
//
//}



//非递归
void reseve1(char *str)

{
	//注意这个错误做法，只改变了临时开辟空间的值
	/*int low = *str;
	int high = *(str + strlen(str) - 1);
	int tmp;
	while (low < high)
	{
		tmp = low;
		low =high;
		high = tmp;
	}*/                               
	char *low = str;                            //str为指针，low和str指针指向同一个空间
	char *high = str + strlen(str) - 1;         //strlen传入的参数就是字符串首元素地址
	char tmp;
	while (low < high)
	{
		tmp = *low;    
		*low = *high;
		*high = tmp;
		low++;                               //连续存储，空间是连着的
		high--;
	}
}


int main()
{ 
	char str[20];                    //传数组
	//char *str="abcde";                     //不能为字符串，因为字符串处于ReadOnly段，不能修改
	/*int low = 0;
	int high = strlen(str)-1;*/
	gets(str);
	reseve(str);         
	//reseve1(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}