#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void Menu()
{
	printf("###########################\n");
	printf("#1.SHOW   2.ADD   3.DEL####\n");
	printf("#4.MOD  5.SEARCH  6SORT###\n");
	printf("#7.CLEAR  8.SAVE  9.EXIT###\n");
	printf("###########################\n");


}
int main()
{
	volatile int quit = 0;      //volatile：易变关键字，一般来保存可见，保持内存的可见性。使其不准直接加载到寄存器，取数据只能在内存里加载。保持内存里的值与寄存器的值一样
	              //为什么quit要用其修饰，因为担心一开始直接加在到寄存器中，中间改变quit值内存中的值变寄存器里的值不变，循环停不下来
	int select = 0;
	contact_p ct;
	Lord(&ct);             //使ct变量指向一个空间，即为ct变量里放一个空间的地址，改变了ct的值，因而传其地址
	while (!quit)
	{
		Menu();
		
		scanf("%d", &select);
		switch (select)
		{
		case 1:Show(ct); break;   //展示ct表示空间里的值 ，不改变自身表示的空间
		case 2:ADD(&ct); break;    //向表示的空间里添加值，其中涉及到扩容，而扩容可能改变其指向的空间，因而传其地址
		case 3:DEL(ct); break;    //向表示的空间里删掉值，而不改变自身表示的空间，因而也传ct的值
		case 4:MOD(ct); break;
		case 5:SEARCH(ct); break;
		case 6:SORT(ct); break;
		case 7:CLEAR(ct); break;
		case 8:Save(ct); break;
		case 9:quit=1; break;
		}


	}



	system("pause");
	return 0;
}