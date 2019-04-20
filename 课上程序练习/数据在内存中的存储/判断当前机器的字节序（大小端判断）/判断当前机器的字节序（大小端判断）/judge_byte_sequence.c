#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Judge1()                   //法一：利用地址int强转char判断。
{
	int i = 1;
	return *(char *)&i;        //i共四个地址，取地址取最小的，再加个强转解引用后只取地址最小空间里的值。
}
int Judge2()                   //法二：利用unio联合体的特点：所有成员共享空间。联合体空间大小为成员所占空间的最大值，空间小的从低地址开始。
{
	union {
		int a;
		char i;
	}u1;
	u1.a = 1;
	return u1.i;
}
int main()
{
	int ret;
	ret = Judge2();
	if (1 == ret)
	{
		printf("小端存储模式\n");
	}
	else if (0 == ret)
	{
		printf("大端存储模式\n");
	}

	system("pause");
	return 0;
}