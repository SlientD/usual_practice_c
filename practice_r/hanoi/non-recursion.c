#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 10  //栈的最大深度
int c = 1;
struct hanoi
{
	int n;
	char x, y, z;
};
void move(char x, int n, char y)
{
	printf("%d号盘移到-->%d号盘 from %c-->%c\n", c++, n, x, y);


}

void push(struct hanoi *p, int top, char x, char y, char z, int n)
{
	p[top + 1].n = n - 1;
	p[top + 1].x = x;
	p[top + 1].y = y;
	p[top + 1].z = z;
}





void fhanoi(struct hanoi *p)
{
	int top = 0;
	while (top >= 0)
	{
		while (p[top].n > 1)
		{
			push(p, top, p[top].x, p[top].z, p[top].y, p[top].n);
			top++;
		}
		if (p[top].n == 1)
		{
			move(p[top].x, 1, p[top].z);
			top--;

		}
		if (top >= 0)
		{
			move(p[top].x, p[top].n, p[top].z);
			top--;
			push(p, top, p[top + 1].y, p[top + 1].x, p[top + 1].z, p[top + 1].n);
			top++;

		}
	}
}

int main()
{ 
	int i;
	struct hanoi p[MAXSTACK];
	c = 1;
	p[0].n = 4;
	p[0].x = 'x', p[0].y = 'y', p[0].z = 'z';
	fhanoi(p);

	system("pause");
	return 0;
}
