#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	strcpy(plist->_head->_data.phonenum, NULL);
	strcpy(plist->_head->_data.name, NULL);
	strcpy(plist->_head->_data.address, NULL);//头节点就只有pre和next 没有date date为空
	plist->_head->_data.age = 0;
	plist->_head->_data.sex = 'w';
	
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;

}
void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopBack(plist);                   
	}
	free(plist->_head);
}
void ListPushBack(List* plist, LTDataType x) //找到头后插
{
	ListInsertAfter(plist->_head, x);
}
void ListPopBack(List* plist)                //后删
{
	ListErase(plist->_head->_next);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}
void ListPopFront(List* plist)
{
	ListErase(plist->_head->_prev);         //前删
}
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (strcmp(cur->_data.name, x.name)==0)
		{
			return cur;
		}
	}
	return NULL;
}
// 在pos的后面进行插入（本质上只有一种插入）
void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->_next;
	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
	
	strcpy(cur->_data.name , x.name);
	cur->_data.age = x.age;
	cur->_data.sex = x.sex;
	strcpy(cur->_data.phonenum, x.phonenum);
	strcpy(cur->_data.address, x.address);
}
// 在pos的后面进行插入，把上述代码的next全部换成pre，把pre成next
void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->_prev;
	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
	strcpy(cur->_data.name, x.name);
	cur->_data.age = x.age;
	cur->_data.sex = x.sex;
	strcpy(cur->_data.phonenum, x.phonenum);
	strcpy(cur->_data.address, x.address);
}
// 删除pos位置的节点
void ListErase(ListNode* pos)
{

	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);


}
void ListRemove(List* plist, LTDataType x)
{
	ListNode* tmp = ListFind(plist, x);
	if (tmp)
	{
		ListErase(tmp);
	}
}

ListNode* ListRemoveDuplicates(List* plist)
{
	ListNode* cur = plist->_head->_next;
	for (cur; cur->_next != plist->_head; cur = cur->_next)
	{
		while (strcmp(cur->_next->_data.name , cur->_data.name)==0)
		{
			ListErase(cur->_next);
		}
	}
	return(plist->_head);
}
void ListNodeChange(ListNode* plist1,ListNode* plist2)
{
	
	ListNode* list2a = plist2->_prev;
	ListNode* list2n = plist2->_next;

	plist1->_prev->_next = plist2;
	plist2->_prev = plist1->_prev;
	plist2->_next = plist1->_next;
	plist1->_next->_prev = plist2;

	list2a->_next = plist1;
	plist1->_prev = list2a;
	plist1->_next = list2n;
	list2n->_prev = plist1;

}
void ListRankInsert(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (Contactcmp(cur->_data,x)>=0)
		{
			break;
		}
	}
	ListInsertFront(cur, x);

}







void ListPrint(List* plist)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next){
		ContactPrint(cur->_data);
	}
	printf("NULL\n");
}
ListNode* ListMerge(List* plist1, List* plist2)
{
	ListNode *cur1 = plist1->_head->_next, *cur2 = plist2->_head->_next;    //*和变量结合
	ListNode *tmp1, *tmp2;
	while (cur1!=plist1->_head&&cur2!=plist2->_head)
	{
		if (strcmp(cur1->_data.name , cur2->_data.name) >1)   //如果链表1的结点小于2的当前节点，则把2结点插到1链表当时链表之前
		{
			tmp1 = cur1->_prev;        //cur1->_prev = cur2;会修改 cur1->_prev，所以要记录下来，使cur1的上一个结点与cur2链接      
			tmp2 = cur2->_next;       //用来记录cur2的最终的结果

			cur2->_next = cur1;     //cur2右手链接cur1
			cur1->_prev = cur2;     //cur1左手拉起cur2
			tmp1->_next = cur2;      //cur1的pre右手拉起cur2
			cur2->_prev = tmp1;      //cur2的左手拉起cur1的pre

			cur2 = tmp2;             //cur2到他的下一个结点，准备下一轮比较
			
		}
		else{
			cur1 = cur1->_next;    //cur1不比cur2当前节点小，那么到他的下一个结点准备下一次比较
		}
	}
	//如果链表2为空，则全部插完了，如果链表1为空，链表2不为空，则把剩下的放到list1中
	if (cur2 != plist2->_head)                   //则cur1==plist1->head
	{
		tmp2 = plist2->_head->_prev;         //记录plist2最后一个结点
		cur2->_prev = cur1->_prev;           //cur2的pre等于cur1的pre
		cur1->_prev->_next = cur2;          //cur1的pre的next等于cur2（指向list当前节点）
		                                      //plist的cur2到尾节点不需要操作
		tmp2->_next = cur1;                 //plist2的尾节点的next等于list1的头节点
		cur1->_prev = tmp2;                 //头结点的pre等于list2的尾节点


	}

	free(plist2->_head);
}

void ListFind(List *plist,char *find,SeqList)            //为什么不能传结构体？--》模糊查找是为了修改值
{


}

//void ListXClassify(List* plist, LTDataType x)
//{
//
//	
//
//}

