#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void move(char x, char y, int *time)  //��ӡÿһ��·��
{
	int t = *time;
	printf("��%d����%c-->%c\n", t,x, y);

}
void hanoi(int n, char x, char y, char z, int *time)   //�ݹ���ÿ�ʼ�ƶ�
{
	if (n >=1)
	{
		hanoi(n - 1, x, z, y, time);
		(*time)++;
		move(x, z, time);
		hanoi(n - 1, y, x, z, time);
	}



}
int main(){
	int n, time=0;
	scanf("%d", &n);
	printf("%d�����ӵ��ƶ������ǣ�\n", n);
	hanoi(n, 'A', 'B', 'C',&time);
	printf("�ƶ���%d��:\n", time);
	system("pause");
	return 0;
}