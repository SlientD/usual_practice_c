#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

void SListInit(SListNode** pphead)
{
	
	*pphead = NULL;

}
SListNode* BuySListNode(SLTDataType x)           //做一个新的结点
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListEraseAfter(SListNode* pos)  //删除pos结点后面的节点
{
	SListNode* tmp = pos->_next;      //-> 有解引用对应数组的[],取值后改的
	if (tmp == NULL)                   //若传入为最后一个节点，则不删除
	{
		return;
	}
	pos->_next = tmp->_next;
	free(tmp);                         //释放地址等于tmp的空间
}

void SListDestory(SListNode** pphead)
{
	while ((*pphead)->_next)
	{
		SListEraseAfter(*pphead);
	}
	free(pphead);
	*pphead = NULL;
}

void SListPushFront(SListNode** pphead, SLTDataType x)   //头插，头节点的地址要换 ，所以要传存头节点地址变量的地址，才能改变头节点地址的值 
{
	SListNode* tmp;
	tmp = BuySListNode(x);
	tmp->_next = *pphead;                               //头插结构体的next要指向原来第一个结构体
	*pphead = tmp;                                       //头节点继续等于第一个元素的地址
}
void SListPopFront(SListNode**  pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->_next;       //tmp等于原第一个节点的next及原节点的下一个节点的地址
	free(*pphead);
	*pphead = tmp;

}
SListNode* SListFind(SListNode* phead, SLTDataType x)//查找
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			return tmp;                        //返回data为x的地址（保存在上一个节点中，for循环中tmp被赋予上一个节点的next值即存放x的结构体的地址）
		}
	}
	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);      //tmp就是新建节点的地址 
	tmp->_next = pos->_next;
	pos->_next = tmp;



}
// 在pos的前面进行插入


void SListRemove(SListNode** pphead, SLTDataType x)   //清除所有值为x的值
{
	SListNode* tmp;
	
	if ((*pphead)->_data==x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; tmp->_next; tmp = tmp->_next)
	{
		if (tmp->_next->_data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}

}
void SLiistAllRemove(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	while (*pphead&&(*pphead)->_data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead;*pphead&& tmp->_next;)
	{
		if (tmp->_next->_data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->_next;
		}
	}





}







void SListAllRemove(SListNode** pphead, SLTDataType x)   //清除所有值为x的值
{
	SListNode* tmp;

	while ((*pphead)&&(*pphead)->_data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; (*pphead) && tmp->_next;)
	{
		if (tmp->_next->_data == x)
		{
			SListEraseAfter(tmp);
		}
		else
			tmp = tmp->_next;

		
	}

}
void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->_next)
	{
		printf("%d->", tmp->_data);
	}
	printf("NULL\n");
}

//链表逆序！！！！！！！！！！！！！！！！！*****************************两种代码重点呀！！！！！！！！！！！！！！！！！
void SListReverse1(SListNode** pphead)
{
	SListNode* head = *pphead;                 //在每个循环中，始终指向该链表的头
	SListNode* tmp = (*pphead)->_next;         //在每个循环中，始终指向要被尾删的节点
	SListNode* oldh = *pphead;                 //在每个循环中，指向原来的头部
	while (tmp)                               //tmp为空，代表逆序结束，旧头的next为空，说明他已经在尾部了
	{
		oldh->_next = tmp->_next;              //后删操作
		tmp->_next = head;                     //让tmp变成新的头，头插操作
		head = tmp;                            //换头部节点
		tmp = oldh->_next;                      //让tmp换成下一个要删除的结点
	} 
	*pphead = head;
	




}
void SListReverse2(SListNode** pphead)
{
	SListNode* pre = *pphead;                 //被执行操作的前一个节点
	SListNode* cur = pre->_next;         //被执行操作的节点
	SListNode* next = cur;                 //被执行操作的后一个节点
	pre->_next = NULL;                     //头部变成了尾节点
	while (next)                               
	{
		next = next->_next;               //在循环开始时，跳到下一个节点，之所以不放在之前赋值，是因为不想让最后next的溢出
		cur->_next = pre;                    //让原本的_next指到前面来
		pre = cur;                           //设置下一次循环的pre节点
		cur = next;                          //设置下一次循环的cur节点

	}
	*pphead = pre;                        //跳出循环后，cur和next都已经指向空了，pre才是头





}