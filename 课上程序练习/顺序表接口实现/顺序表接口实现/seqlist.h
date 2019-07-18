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
	SLDataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capacity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
void SeqListInit(SeqList* psl, size_t capacity);                //初始化这个顺序表
void SeqListDestory(SeqList* psl);                              //释放这个顺序表
void CheckCapacity(SeqList* psl);                               //检查并扩容
void SeqListPushBack(SeqList* psl, SLDataType x);              //在尾部插入某个值
void SeqListPopBack(SeqList* psl);                             //在尾部pop值出去
void SeqListPushFront(SeqList* psl, SLDataType x);             //在头部插入某值进去
void SeqListPopFront(SeqList* psl);                           //头部的值pop出去
int SeqListFind(SeqList* psl, SLDataType x);                  //寻找某个数的下标
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);   //在某个位置上插入某值
void SeqListErase(SeqList* psl, size_t pos);                 //擦除某个位置上的值
void SeqListRemove(SeqList* psl, SLDataType x);             //移除第一次出现的某个值
void SeqListAllRemove(SeqList* psl, SLDataType x);           //移除所有的某个值
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);//修改固定位置上的数为x值
void SeqListPrint(SeqList* psl);                        //数组打印
// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl);                  //冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x);     //二分法查找



#endif