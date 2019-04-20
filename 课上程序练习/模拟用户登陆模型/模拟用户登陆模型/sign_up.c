#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//char password[20];
	//printf("%d\n", &password);   //元组地址
	//printf("%d", password);      //元素首地址


	int i = 0;
	char password[20] = { 0 };   //数组没有初始化就是随机值
	printf("请输入你的密码：");
	for (i = 0; i < 3; i++)
	{
		scanf("%s", password);//password是代表首地址，&password表示数组的首地址
		if ((strcmp(password, "123456")) == 0)  //strcmp 字符串比较函数，两个字符串相等返回0，前者大于后者返回大于0的数，后者大于前者返回小于0的数
		{
			printf("登陆成功\n");
			break;
		}
		else printf("密码输入错误，请重新输入\n");

	}
	if (i == 3)
		printf("三次密码均输入错误，退出登陆系统\n");

	system("pause");
	return 0;
}