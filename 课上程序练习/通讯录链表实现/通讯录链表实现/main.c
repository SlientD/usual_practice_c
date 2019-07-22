#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include "List.h"
#include "seqlist.h"

int main()
{
	int flag = 0;
	int select;
	List list;
	ListInit(&list);

	Meau();
	scanf("%d", &select);
	do{
		switch (select)
		{
		case 1:ListPrint(&list);
		case 2:FindPeople(&list);
		case 3:
		}




	} while (!flag)




	system("pause");
	return 0;
}