#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��Ŀ��ɾ���ַ�����β�Ŀո��м�������ո�ֻ��һ����ԭ���ַ���˳�򲻱䣬�磺"*****as*****adjj*ji**"��Ϊ"as*adjj*ji"(*Ϊ�ո�)

//˼·����֮ǰд����һ���ַ�����ɾ����Ӧ��ĸ��˼·һ���������м���ֵ������ո�Ҫ����һ���ո��Ƕ�Ӧ������Ӧ�ı䣺�����м�ո�ʱ����������ո��step��
//�ò�����һ���ɡ���ÿ����һ���ո�μ�һ������Ҫ��ȷ�����м�Ŀո��ַ������ж���������ʼ����ո��ַ���ʱ����λ�ò���0�����ų���ͷ��step���Ϻ�û�����ϡ�\0��(�ų���β)


void DeleteSpace(char *str)
{
	int i;
	int step=0;
	int flag = 0;
	int tmp;
	for (i = 0; *(str + i);i++){

		tmp = step;
		if (*(str + i + step) == ' '){
			while (*(str + i + step) == ' ')
			{

				step++;
			}
			if (i != 0 && *(str + i + step))
			{
				step--;
			}
			
		}
		*(str + i) = *(str + i + step);
	}
	
	
}
int main()
{
	char str[] = "    ab cc  x   ";
	DeleteSpace(str);
	printf("%s", str);

	system("pause");
	return 0;
}