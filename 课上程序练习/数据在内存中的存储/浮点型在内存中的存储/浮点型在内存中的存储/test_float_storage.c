#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



int main()
{
	int n = 9;                        //0000 0000 0000 0000 0000 0000 0000 1001
	float pFloat = (float)n;          //��9ȡ����תΪ�����ͣ��ٴ��pFloat
	float *pfloat = (float *)&n;      //��n�ĵ�ַתΪ��������ַ��������n�ķ�ʽ��Ϊ������)��
	printf("n=%d\n", n);
	printf("pFloat=%f\n", pFloat);
	printf("*float=%f\n", *pfloat);   //�����ú��Ը�������ʽ�����ռ����ֵ  0 00000000 00000000000000000001001   S=0,E=0,(-127)
	*pfloat = 9.0;                    //1001 ʵ��n�ռ��д��ֵ0 00000011 00100000000000000001001 
	printf("n=%d\n", n);              //ת��Ϊ����Ϊ 1091567616
	printf("*float=%f\n", *pfloat);   // 9.000000
	system("pause");
	return 0;
}

