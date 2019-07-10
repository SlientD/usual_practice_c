#define _CRT_SECURE_NO_WARNINGS 1
//两矩形相交面积
#include <stdio.h>
#include <stdlib.h>
//#define min(x,y) ((x)<(y)?(x):(y))
//#define max(x,y) ((x)>(y)?(x):(y))
//stdlib 文件中有

int main()
{
	float x1, y1, x2, y2, x3, y3, x4, y4;
	float minx, miny, maxx, maxy;
	
	printf("请输入第两个矩形中四个点的横纵坐标:\n");
	scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	maxx = min(max(x1,x2), max(x3,x4));                  //最大中最小的
	maxy = min(max(y1, y2), max(y3, y4));                //最小中最大的
	minx = max(min(x1, x2), min(x3, x4));
	miny = max(min(y1, y2), min(y3, y4));
	if (maxx <= minx || maxy <= miny)
		printf("S=0.00\n");
	else
		printf("S=%.2f\n", (maxx - minx)*(maxy - miny));
	system("pause");
	return 0;
}