#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{    //����һ��
	char *str = "hello";                 //����redonly data��  ��ֻ���������޸�
	*(str + 1) = 'g';                    //str+1   Ҫ��str��ʲô���͵ģ�����char��Ϊ��1���ֽڵ�ֵ����Ϊint��4���ֽڵ�ֵ
	printf("%s\n", str);

	strcpy(str, "abc");                  //���ڲ����޸ģ����Բ�����strcpy����
	printf("%s\n", str);

	//�������
	/*char *str2 = "hello";            //�޸�Ϊ�ַ����鼴��
	str2[1] = 'g';
	strcpy(str, "abc");                  
	printf("%s\n", str);*/

	//�������
	int *p= 0;                           //Ұָ�룬δ��ʼ��p
	*p = 0;
	printf("%d", *p);



	system("pause");
	return 0;

}
//ʲô��Ұָ�룿
//��ָ������ڴ棬Ҫ��ָ���ڵ�ַ�ǳ���ָ���ģ���֤ȷʵ����Ч��ַ��������Ч��ַ��
//���п����ƻ��������򣨻��߲���ϵͳ���Ĺؼ����ݣ�����ϵͳ���ϡ�
//��α��⣿

