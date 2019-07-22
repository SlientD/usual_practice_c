#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _CONTACT_H_
#define _CONTACT_H_




typedef struct{

	char name[32];
	char sex;
	char age;
	char phonenum[13];
	char address[256];

}Contact;
void ContactInit(Contact *con);
void FillDate();




#endif