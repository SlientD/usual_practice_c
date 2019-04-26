


#ifndef _SHORT_DISTANCE_
#define _SHORT_DISTANCE_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>


#define MaxSize 100     
#define VISITED 1       
#define NOTVISITED 0    
#define Infinite 1073741823  
#define MaxViewNum 50     /*景点个数最大50*/
#define MaxRoad 1000      /*定义路径为无穷大*/
#define N 13              /*目前景点个数*/

typedef struct

{

	char name[30];          /*景点名称*/

	char number[10];        /*景点代号*/

	char introduce[200];    /*景点介绍*/

}Elemtype;                  /*景点信息*/



typedef struct

{

	int num;              /*景点编号*/

	Elemtype date;        /*景点信息*/

}View;                    /*定义景点*/

typedef struct

{

	View view[MaxViewNum];         /*存放顶点的一维数组，数组第零单元没有用上*/

	int length[MaxViewNum][MaxViewNum];  /*存放路径长度*/

	int m, n;

}MGraph;

MGraph MGr;              /*全局变量,定义MGr为MGraph类型*/







void init();
void introduce();
void input();
void Push();
int Pop();
int minD();
void output_path();
void distance();
void map();


#endif 




