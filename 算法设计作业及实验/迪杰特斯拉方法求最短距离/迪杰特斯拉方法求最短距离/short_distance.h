


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
#define MaxViewNum 50     /*����������50*/
#define MaxRoad 1000      /*����·��Ϊ�����*/
#define N 13              /*Ŀǰ�������*/

typedef struct

{

	char name[30];          /*��������*/

	char number[10];        /*�������*/

	char introduce[200];    /*�������*/

}Elemtype;                  /*������Ϣ*/



typedef struct

{

	int num;              /*������*/

	Elemtype date;        /*������Ϣ*/

}View;                    /*���徰��*/

typedef struct

{

	View view[MaxViewNum];         /*��Ŷ����һά���飬������㵥Ԫû������*/

	int length[MaxViewNum][MaxViewNum];  /*���·������*/

	int m, n;

}MGraph;

MGraph MGr;              /*ȫ�ֱ���,����MGrΪMGraph����*/







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




