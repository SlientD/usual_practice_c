#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=1;
	char c='a';
	double d = 3.14;
	char buf[64];
	//FILE* pf = fopen("file_test.txt", "wb");   //�ļ�ָ�붨�� FILE*���壬fopen�����ļ����򿪷�ʽ��
	FILE* pf = fopen("file_tester.bin", "wb");
	if (NULL == pf)
	{
		printf("error(%d):%s", errno, strerror(errno));  
	}
	////1.fputs:int fputs(const char*str,FILE* stream)   �ı������������δ��ʽ��(%d��Щ������)���ļ���д����    ��puts��const char*str��������ʾ���ϴ�ʡ��stdout��
	//fputs("abcd%c,\n",stdout);  //stout��ʾ������ʾ��Ҳ���ļ���
	
	//i = 10;
	///*while (i--)
	//{
	//	fputs("abcd\n", pf);
	//}*/


	////2.fgets:char* fgets(char *str,int num,FILE* stream) �ı������뺯����δ��ʽ����
	//i = 10;
	//while (i--)
	//{
	//	fgets(buf, 32, pf);
	//	fputs(buf, stdout);
	//}
	


 //   //3.fputc:int fputc(int character,FILE* stream)   (putchar(int character)����ʾ���ϴ�ʡ��stdout)
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
	//5.fprintf:int fprintf(FILE *stream,const char* format,..) ����ʽ������д��������printf����FILE *stream
	fprintf (pf,"%d,%c,%f",i,c,d);

	//6.fscanf:scanf(FILE *stream,const char* format,..)
	fscanf(pf,"%d %c%lf", &i, &c, &d);
	printf( "%d,%c,%f", i, c, d);

	//7.sprintf:int sprintf(char* str,const char* format,..)  ���ַ���"����"���뵽��������buf��
	sprintf(buf, "int:%d,char:%c,double:%f", i, c, d);
	printf("%s\n", buf);

	//8.sscanf(const char*s,const char* format,..)
	int a, b;
	char* msg = "a=10,b=c";
	sscanf(msg, "a=%d,b=%c", &a, &b);
	printf("%d,%c", a, b);*/


	////9.fseek:int fseek (FILE *stream,longint offset,int origin) �ı��ļ���дλ��
	//fputs("this is an apple.", pf);
	//fseek(pf, 0, SEEK_CUR);     //����󣬹�������һ���ֵ����
	//fputs("...", pf);
	//fseek(pf, 9, SEEK_SET);    // �������ʱ�Ĺ�꣬��ʼ���ֵ�ʱ����û����+1���ڶ����ֵ�ǰ�棬+n����n+1���ֵ�ǰ�棬�������Ҫ��ʼ�ĵĵط�
	//fputs(" sam", pf);

	//fseek(pf, -2, SEEK_END);  //�ӵ����ڶ���λ�ÿ�ʼ��д����һ��굽���һ���ֵ�ǰ��
	//fputs("nd", pf);

	////10.ftell:long int ftell(FILE* stream) �����ļ�ָ���������ʼλ�õ�ƫ����
	/*for (i = 0; i < 26; i++)
	{
		printf("ftell:%d\n", ftell(pf));
		putc('A' + i, pf);
	}*/
	//printf("ftell:%d\n", ftell(pf));
	//fseek(pf, 9, SEEK_SET);
	//printf("ftell:%d\n", ftell(pf));

	//11.rewind: void rewind (FILE* stream) ���ļ�ָ���λ�ûص��ļ�����ʼλ�� ��fseek(fp,0,SEEK_SET)��ͬ
	////12.fread:size_t fread( void *buffer, size_t size, size_t count, FILE *stream ) ���ļ�����ֽڵ�������
	//fread(buf, 1, 26, pf);
	//printf("%s\n", buf);
	//13.feof:int feof(FILE* stream):1���ж��ı��ļ��Ƿ��ȡ�������жϷ���ֵ�Ƿ�ΪEOF(->fgetc)����NULL(->fgets��)  
	//                               2���ж϶������ļ��Ƿ��ȡ�������жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�������fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
	//                      feof���ױ�����ʹ����Ϊ��ȡ�ļ�������ԭ��һ�������ļ�β������Ҳ�п����Ƕ�ȡʧ�ܽ��������Ҫ�ж�������ԭ����feof������,���Ҫ��ferror����ʹ��
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
	while ((ret_code = fread(&d, sizeof(double), 1, pf)) >= 1)  //�ж���û�ж���������������
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