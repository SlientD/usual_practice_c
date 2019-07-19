#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_data = NULL;                              //ͷ�ڵ��ֻ��pre��next û��date dateΪ��
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
void ListPushBack(List* plist, LTDataType x) //�ҵ�ͷ���
{
	ListInsertAfter(plist->_head, x);
}
void ListPopBack(List* plist)                //��ɾ
{
	ListErase(plist->_head->_next);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}
void ListPopFront(List* plist)
{
	ListErase(plist->_head->_prev);         //ǰɾ
}
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
// ��pos�ĺ�����в��루������ֻ��һ�ֲ��룩
void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->_next;
	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
	cur->_data = x;
}
// ��pos�ĺ�����в��룬�����������nextȫ������pre����pre��next
void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->_prev;
	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
	cur->_data = x;
}
// ɾ��posλ�õĽڵ�
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
void ListPrint(List* plist)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next){
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
ListNode* ListRemoveDuplicates(List* plist)
{
	ListNode* cur = plist->_head->_next;
	for (cur; cur->_next != plist->_head; cur = cur->_next)
	{
		while (cur->_next->_data == cur->_data)
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
void ListXClassify(List* plist, LTDataType x)
{
	

}

