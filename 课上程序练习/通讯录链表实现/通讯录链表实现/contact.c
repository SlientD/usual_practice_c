#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include "List.h"


void Meau()
{
	printf("1.查看所有用户");
	printf("2.查找");
	printf("3.新建联系人");
	printf("4.删除联系人");
	printf("5.删除所有联系人");

}

void FillDate(Contact* con,char* name,char sex,int age,char* phonenum,char*  address)   //通过接受形参来赋值
{
	strcpy(con->name, name);       //数组不可整体赋值，只可以用strcpy来赋值
	con->sex=sex;
	con->age=age;
	strcpy(con->phonenum,phonenum);
	strcpy(con->address,address);
}

Contact DateInput()
{
	Contact ret;
	scanf("%[^\n]", ret.name);
	getchar();
	scanf("%c", &ret.sex);
	scanf("%d", &ret.age);
	scanf("%[^\n]", ret.phonenum);
	getchar();
	scanf("%[^\n]", ret.address);

}

int ContactCmp(Contact c1, Contact c2)
{
	return strcmp(c1.name, c2.name);
}
void ContactPrint(Contact date)
{
	//表头
	printf("%15s %c %2d %12s %s \n",
		date.name,
		date.sex,
		date.address,
		date.phonenum,
		date.address);
}