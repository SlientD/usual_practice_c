#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Judge1()                   //��һ�����õ�ַintǿתchar�жϡ�
{
	int i = 1;
	return *(char *)&i;        //i���ĸ���ַ��ȡ��ַȡ��С�ģ��ټӸ�ǿת�����ú�ֻȡ��ַ��С�ռ����ֵ��
}
int Judge2()                   //����������unio��������ص㣺���г�Ա����ռ䡣������ռ��СΪ��Ա��ռ�ռ�����ֵ���ռ�С�Ĵӵ͵�ַ��ʼ��
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
		printf("С�˴洢ģʽ\n");
	}
	else if (0 == ret)
	{
		printf("��˴洢ģʽ\n");
	}

	system("pause");
	return 0;
}