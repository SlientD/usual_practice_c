#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include "List.h"


void Meau()
{
	printf("1.�鿴�����û�");
	printf("2.����");
	printf("3.�½���ϵ��");
	printf("4.ɾ����ϵ��");
	printf("5.ɾ��������ϵ��");

}

void FillDate(Contact* con,char* name,char sex,int age,char* phonenum,char*  address)   //ͨ�������β�����ֵ
{
	strcpy(con->name, name);       //���鲻�����帳ֵ��ֻ������strcpy����ֵ
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
	//��ͷ
	printf("%15s %c %2d %12s %s \n",
		date.name,
		date.sex,
		date.address,
		date.phonenum,
		date.address);
}