#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define NAME_SIZE 64      //最好定义为2的倍数
#define TEL_SIZE 16
#define ASSR_SIZE 128
#define LIST_DEFAULT 2
#define INC_DEFAULT 2
#define CT_FILE "contact_file.bin" //以二进制形式保存，可以整体读写
typedef struct person
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char telephone[TEL_SIZE];
	char address[ASSR_SIZE];

}person_t, *person_p,**person_pp;

typedef struct contact{
	int cap;     //容量
	int size;    //当前的人
	person_t list[0];//柔性数组


}contact_t,*contact_p,**contact_pp;

//方法：
void Init(contact_pp ct);
void ADD(contact_pp ct);
void DEL(contact_p ct);     //1.与最后一个人交换位置，使size-1   2.是这标志位
void MOD(contact_p ct);
void SEARCH(contact_p ct);
void SORT(contact_p ct);      //字符串比较
void ClEAR(contact_p ct);      //size=0
void Show(contact_p ct);

void Save(contact_p ct);
void Lord(contact_pp ct);






#endif // !_CONTACT_H_
