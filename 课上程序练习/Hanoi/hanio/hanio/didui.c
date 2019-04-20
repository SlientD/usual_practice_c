#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void move(char x, char y, int *time)  //打印每一步路径
{
	int t = *time;
	printf("第%d步：%c-->%c\n", t,x, y);

}
void hanoi(int n, char x, char y, char z, int *time)   //递归调用开始移动
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
	printf("%d个盘子的移动方法是：\n", n);
	hanoi(n, 'A', 'B', 'C',&time);
	printf("移动了%d次:\n", time);
	system("pause");
	return 0;
}