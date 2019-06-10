#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define NAME_SIZE 64      //��ö���Ϊ2�ı���
#define TEL_SIZE 16
#define ASSR_SIZE 128
#define LIST_DEFAULT 2
#define INC_DEFAULT 2
#define CT_FILE "contact_file.bin" //�Զ�������ʽ���棬���������д
typedef struct person
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char telephone[TEL_SIZE];
	char address[ASSR_SIZE];

}person_t, *person_p,**person_pp;

typedef struct contact{
	int cap;     //����
	int size;    //��ǰ����
	person_t list[0];//��������


}contact_t,*contact_p,**contact_pp;

//������
void Init(contact_pp ct);
void ADD(contact_pp ct);
void DEL(contact_p ct);     //1.�����һ���˽���λ�ã�ʹsize-1   2.�����־λ
void MOD(contact_p ct);
void SEARCH(contact_p ct);
void SORT(contact_p ct);      //�ַ����Ƚ�
void ClEAR(contact_p ct);      //size=0
void Show(contact_p ct);

void Save(contact_p ct);
void Lord(contact_pp ct);






#endif // !_CONTACT_H_
