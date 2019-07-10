#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char *strcat2(char *destination,const char *source)
{
	assert(destination != NULL && source != NULL);
	char *ret = destination;
	while (*destination)        //源从目标的结束符开始赋值，所以传参时源和目标不能为同一个实参，否则会没有尽头的赋值。
	{
		destination++;                
	}
	/* *destination = *source;
	while (*(source-1))
	{
		*destination = *source;
		source++;
		destination++;
	}*/
	while (*destination++ = *source++);        //源中的结束符也要赋进去，因此先赋值判0
	return ret;


}
int main()
{
	char *a = "def";      
	char b[10] = "abc";    //若不写开辟空间元素个数，默认给b开辟的空间为4个字节，再续字符串会出现b栈溢出
	//strcat(b, a);        
	strcat2(b, a);
	printf("b=%s\n", b);
	system("pause");
	return 0;
}