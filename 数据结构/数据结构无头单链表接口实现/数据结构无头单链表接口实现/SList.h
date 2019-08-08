#ifndef _SLIST_H_
#define _SLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);
SListNode* BuySListNode(SLTDataType x);            //做一个新的结点
void SListPushFront(SListNode** pphead, SLTDataType x);  
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);//查找
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListAllRemove(SListNode** pphead, SLTDataType x);
void SListPrint(SListNode* phead);
SLTDataType SListTailFind(SListNode* pphead, int k);      //找倒数第k个结点
void SListReverse1(SListNode** pphead);     //逆序！！！！！！重点
void SListReverse2(SListNode** pphead);     //逆序！！！！！！重点


//输入两个链表，找出它们的第一个公共结点。没交点返回空，不可以改变链表的值，链表中无循环，时间复杂度O（n），空间复杂度O(1);
//右对齐思想，让长的链先走几步，等一样长的时候比较。比较 的时候比较地址，而不是数据
SListNode* SListFindCommenNode(SListNode* phead1, SListNode*phead2);

// 给定一个链表，判断链表中是否有环。
int exitCycle(SListNode* phead1);


//给定一个链表，判断链表中是否有环。 有环的话返回环的起始点
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
//跑道相遇思想：两个人在操场绕圈跑，起点在起跑线，如果一个人以2v跑，一个人以v跑，那么他们将在起点（开始一起走的地方）相遇。
//   若是起点不不在操场内，而是在宿舍，宿舍到起点的距离为x，那就可以理解为后退到在距离起点x的地方开始跑，（即距离起点x地方作为两人开始跑的地方）那么相遇的地方就在距离起点x的地方
//找到最终相遇的地方后，由于宿舍到起跑线和相遇地方到起跑线的距离相同，那么用SListFindCommenNode函数，就可以找到起跑线
SListNode * detectCycle(SListNode* head);


#endif
