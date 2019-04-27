#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



int main()
{
	int n = 9;                        //0000 0000 0000 0000 0000 0000 0000 1001
	float pFloat = (float)n;          //将9取出，转为浮点型，再存给pFloat
	float *pfloat = (float *)&n;      //将n的地址转为浮点数地址（即看待n的方式变为浮点数)。
	printf("n=%d\n", n);
	printf("pFloat=%f\n", pFloat);
	printf("*float=%f\n", *pfloat);   //解引用后以浮点数形式看待空间里的值  0 00000000 00000000000000000001001   S=0,E=0,(-127)
	*pfloat = 9.0;                    //1001 实际n空间中存的值0 00000011 00100000000000000001001 
	printf("n=%d\n", n);              //转换为整数为 1091567616
	printf("*float=%f\n", *pfloat);   // 9.000000
	system("pause");
	return 0;
}

