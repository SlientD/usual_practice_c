#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capacity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
void SeqListInit(SeqList* psl, size_t capacity);                //��ʼ�����˳���
void SeqListDestory(SeqList* psl);                              //�ͷ����˳���
void CheckCapacity(SeqList* psl);                               //��鲢����
void SeqListPushBack(SeqList* psl, SLDataType x);              //��β������ĳ��ֵ
void SeqListPopBack(SeqList* psl);                             //��β��popֵ��ȥ
void SeqListPushFront(SeqList* psl, SLDataType x);             //��ͷ������ĳֵ��ȥ
void SeqListPopFront(SeqList* psl);                           //ͷ����ֵpop��ȥ
int SeqListFind(SeqList* psl, SLDataType x);                  //Ѱ��ĳ�������±�
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);   //��ĳ��λ���ϲ���ĳֵ
void SeqListErase(SeqList* psl, size_t pos);                 //����ĳ��λ���ϵ�ֵ
void SeqListRemove(SeqList* psl, SLDataType x);             //�Ƴ���һ�γ��ֵ�ĳ��ֵ
void SeqListAllRemove(SeqList* psl, SLDataType x);           //�Ƴ����е�ĳ��ֵ
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//�޸Ĺ̶�λ���ϵ���Ϊxֵ
void SeqListPrint(SeqList* psl);                        //�����ӡ
// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl);                  //ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x);     //���ַ�����



#endif