#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{    //问题一：
	char *str = "hello";                 //放于redonly data段  （只读）不能修改
	*(str + 1) = 'g';                    //str+1   要看str是什么类型的，若是char则为加1个字节的值，若为int加4个字节的值
	printf("%s\n", str);

	strcpy(str, "abc");                  //由于不可修改，所以不能用strcpy函数
	printf("%s\n", str);

	//解决方法
	/*char *str2 = "hello";            //修改为字符数组即可
	str2[1] = 'g';
	strcpy(str, "abc");                  
	printf("%s\n", str);*/

	//问题二：
	int *p= 0;                           //野指针，未初始化p
	*p = 0;
	printf("%d", *p);



	system("pause");
	return 0;

}
//什么是野指针？
//用指针访问内存，要求指针内地址是程序指定的，保证确实是有效地址，若是无效地址，
//会有可能破坏其他程序（或者操作系统）的关键数据，导致系统故障。
//如何避免？

