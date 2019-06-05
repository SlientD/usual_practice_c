#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=1;
	char c='a';
	double d = 3.14;
	char buf[64];
	//FILE* pf = fopen("file_test.txt", "wb");   //文件指针定义 FILE*定义，fopen（打开文件，打开方式）
	FILE* pf = fopen("file_tester.bin", "wb");
	if (NULL == pf)
	{
		printf("error(%d):%s", errno, strerror(errno));  
	}
	////1.fputs:int fputs(const char*str,FILE* stream)   文本行输出函数，未格式化(%d这些都不变)往文件里写函数    （puts（const char*str），往显示器上打，省略stdout）
	//fputs("abcd%c,\n",stdout);  //stout显示器（显示器也是文件）
	
	//i = 10;
	///*while (i--)
	//{
	//	fputs("abcd\n", pf);
	//}*/


	////2.fgets:char* fgets(char *str,int num,FILE* stream) 文本行输入函数，未格式化的
	//i = 10;
	//while (i--)
	//{
	//	fgets(buf, 32, pf);
	//	fputs(buf, stdout);
	//}
	


 //   //3.fputc:int fputc(int character,FILE* stream)   (putchar(int character)往显示器上打，省略stdout)
	///*for (i = 0; i < 26; i++)
	//{
	//	fputc('A' + i, pf);
	//}*/


	////4.fgetc:int fgetc(FILE* stream)    
	//for (i = 0; i < 26; i++)
	//{
	//	c = fgetc(pf);
	//	printf("%c", c);
	//}

	/*
	//5.fprintf:int fprintf(FILE *stream,const char* format,..) 将格式化数据写入流，比printf多了FILE *stream
	fprintf (pf,"%d,%c,%f",i,c,d);

	//6.fscanf:scanf(FILE *stream,const char* format,..)
	fscanf(pf,"%d %c%lf", &i, &c, &d);
	printf( "%d,%c,%f", i, c, d);

	//7.sprintf:int sprintf(char* str,const char* format,..)  把字符串"。。"输入到缓冲区（buf）
	sprintf(buf, "int:%d,char:%c,double:%f", i, c, d);
	printf("%s\n", buf);

	//8.sscanf(const char*s,const char* format,..)
	int a, b;
	char* msg = "a=10,b=c";
	sscanf(msg, "a=%d,b=%c", &a, &b);
	printf("%d,%c", a, b);*/


	////9.fseek:int fseek (FILE *stream,longint offset,int origin) 改变文件读写位置
	//fputs("this is an apple.", pf);
	//fseek(pf, 0, SEEK_CUR);     //输入后，光标在最后一个字的最后
	//fputs("...", pf);
	//fseek(pf, 9, SEEK_SET);    // 想想打字时的光标，开始打字的时候光标没动，+1到第二个字的前面，+n到第n+1个字的前面，光标后就是要开始改的地方
	//fputs(" sam", pf);

	//fseek(pf, -2, SEEK_END);  //从倒数第二个位置开始读写，减一光标到最后一个字的前面
	//fputs("nd", pf);

	////10.ftell:long int ftell(FILE* stream) 返回文件指针相对于起始位置的偏移量
	/*for (i = 0; i < 26; i++)
	{
		printf("ftell:%d\n", ftell(pf));
		putc('A' + i, pf);
	}*/
	//printf("ftell:%d\n", ftell(pf));
	//fseek(pf, 9, SEEK_SET);
	//printf("ftell:%d\n", ftell(pf));

	//11.rewind: void rewind (FILE* stream) 让文件指针的位置回到文件的起始位置 与fseek(fp,0,SEEK_SET)相同
	////12.fread:size_t fread( void *buffer, size_t size, size_t count, FILE *stream ) 从文件里读字节到缓存区
	//fread(buf, 1, 26, pf);
	//printf("%s\n", buf);
	//13.feof:int feof(FILE* stream):1》判断文本文件是否读取结束（判断返回值是否为EOF(->fgetc)，或NULL(->fgets）)  
	//                               2》判断二进制文件是否读取结束：判断返回值是否小于实际要读的个数例如fread判断返回值是否小于实际要读的个数
	//                      feof容易被错误使用因为读取文件结束的原因一是遇到文件尾结束，也有可能是读取失败结束，因而要判断是那种原因导致feof不成立,因而要与ferror联合使用
	/*while ((c = fgetc(pf)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	if (ferror(pf))
	{
		puts("I/O error when reading\n");
	}
	else if (feof(pf))
	{
		puts("End of file reached successfully\n");
	}*/
	
	double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	size_t ret_code = 0;
	fwrite(a, sizeof(*a), 5, pf);
	fclose(pf);
	pf = fopen("file_tester.bin", "rb");
	while ((ret_code = fread(&d, sizeof(double), 1, pf)) >= 1)  //判断有没有读到基本个数个数
	{
		printf("%lf\n", d);
	}
	if (ferror(pf))
		printf("error reading!\n");
	else if (feof(pf))
	{
		puts("End of file reached successfully\n");
	}
	fclose(pf);
	pf=NULL;






	
	system("pause");
	return 0;
}