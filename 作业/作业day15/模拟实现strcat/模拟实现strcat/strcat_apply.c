#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char *strcat2(char *destination,const char *source)
{
	assert(destination != NULL && source != NULL);
	char *ret = destination;
	while (*destination)        //Դ��Ŀ��Ľ�������ʼ��ֵ�����Դ���ʱԴ��Ŀ�겻��Ϊͬһ��ʵ�Σ������û�о�ͷ�ĸ�ֵ��
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
	while (*destination++ = *source++);        //Դ�еĽ�����ҲҪ����ȥ������ȸ�ֵ��0
	return ret;


}
int main()
{
	char *a = "def";      
	char b[10] = "abc";    //����д���ٿռ�Ԫ�ظ�����Ĭ�ϸ�b���ٵĿռ�Ϊ4���ֽڣ������ַ��������bջ���
	//strcat(b, a);        
	strcat2(b, a);
	printf("b=%s\n", b);
	system("pause");
	return 0;
}