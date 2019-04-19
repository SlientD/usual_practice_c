#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//水仙花数不只是3位数，几位数几次方
//方法：1、先求位数 2、求各个位的数 3，方后加
int main(){
	int i,t,number,c;
	int a[10];
	int sum;
	
	
	for (number = 1; number < 999; number++)
	{//求位数、各个位的数
		sum = 0;
		t = 0;
		i = number;
		while (i)
		{
			
				a[t] = i % 10; //0存个位开始
				t++;           //t位数		
				i = i / 10;    //改变值
			
		}
		
	//求和
		c = t;
		while (t--)
			sum += pow(a[t], c);

	//次方加后判断
		if (sum == number)
			printf("%d\n", number);

	}
	
	system("pause");

	return 0;
}