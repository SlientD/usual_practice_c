#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�ݹ�
void reseve(char *str)

{
	int len = strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str+1) > 1)
	{
		reseve(str+1);
	}
	*(str+len-1)= tmp;                 //str֮ǰ�ĵ�λ�ã�len֮���λ���ظ���strָ��λ��
}



//ֻ�ݲ���
//void reseve(char *str,int low,int high)
//
//{
//	if (low < high)
//	{
//		str[low] = str[high] ^ str[low];
//		str[high] = str[high] ^ str[low];
//		str[low] = str[high] ^ str[low];
//		reseve(str, low + 1, high - 1);
//	}
//
//}



//�ǵݹ�
void reseve1(char *str)

{
	//ע���������������ֻ�ı�����ʱ���ٿռ��ֵ
	/*int low = *str;
	int high = *(str + strlen(str) - 1);
	int tmp;
	while (low < high)
	{
		tmp = low;
		low =high;
		high = tmp;
	}*/                               
	char *low = str;                            //strΪָ�룬low��strָ��ָ��ͬһ���ռ�
	char *high = str + strlen(str) - 1;         //strlen����Ĳ��������ַ�����Ԫ�ص�ַ
	char tmp;
	while (low < high)
	{
		tmp = *low;    
		*low = *high;
		*high = tmp;
		low++;                               //�����洢���ռ������ŵ�
		high--;
	}
}


int main()
{ 
	char str[20];                    //������
	//char *str="abcde";                     //����Ϊ�ַ�������Ϊ�ַ�������ReadOnly�Σ������޸�
	/*int low = 0;
	int high = strlen(str)-1;*/
	gets(str);
	reseve(str);         
	//reseve1(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}