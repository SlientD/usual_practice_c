#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//类型定义：typedef 给一个类型起别名
//加上typedef，会由变量提升为这种类型。
typedef define const  的区别？    
//typedef int INT;
//typedef unsigned int UNIT;
//typedef int Arr[10];
//typedef int(*PFUN)[10]; //指向数组的指针--》数组指针
//typedef int(*PFUN)(int, int); //函数指针





void star()
{
	printf("********************************\n");
	printf("*******     1.play      ********\n");
	printf("*******     0.exit      ********\n");
	printf("********************************\n");


}
void play()
{
	int ret = rand()%100+1;            //产生1-100随机数
	int guss;
	printf("请输入你所猜的数：");
//	printf("%d\n", ret);               查看随机生成数
	while (1)
	{
		scanf("%d", &guss);
		if (guss > ret)
		{
			printf("猜大了，继续猜\n");
		}
		else if (guss < ret)
		{
			printf("猜小了，继续猜\n");
		}
		     else
		    {
			printf("猜对了，嘿嘿嘿\n");
			break;
		     }
	}


}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));        //设置起始变量，整个程序设置一次就够了
	do{
		star();                          //打印起始界面
		printf("你要玩游戏吗？\n");
		scanf("%d", &input);             //选择要不要玩游戏
		switch (input)
		{
		case 1: play(); break; 
		case 0: printf("游戏结束\n"); break;
		default:printf("输入错误请重新输入\n"); break;
			      
		}
			
		    
	} while (input);                       //input=0时直接结束，等于其他你还可以玩，所以那input作为控制循环变量很好


	system("pause");
	return 0;
}