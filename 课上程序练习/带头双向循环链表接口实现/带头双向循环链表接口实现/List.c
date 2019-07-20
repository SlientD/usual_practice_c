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
void ListPrint(List* plist)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next){
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
ListNode* ListMerge(List* plist1, List* plist2)
{
	ListNode *cur1 = plist1->_head->_next, *cur2 = plist2->_head->_next;    //*�ͱ������
	ListNode *tmp1, *tmp2;
	while (cur1!=plist1->_head&&cur2!=plist2->_head)
	{
		if (cur1->_data > cur2->_data)    //�������1�Ľ��С��2�ĵ�ǰ�ڵ㣬���2���嵽1����ʱ����֮ǰ
		{
			tmp1 = cur1->_prev;        //cur1->_prev = cur2;���޸� cur1->_prev������Ҫ��¼������ʹcur1����һ�������cur2����      
			tmp2 = cur2->_next;       //������¼cur2�����յĽ��

			cur2->_next = cur1;     //cur2��������cur1
			cur1->_prev = cur2;     //cur1��������cur2
			tmp1->_next = cur2;      //cur1��pre��������cur2
			cur2->_prev = tmp1;      //cur2����������cur1��pre

			cur2 = tmp2;             //cur2��������һ����㣬׼����һ�ֱȽ�
			
		}
		else{
			cur1 = cur1->_next;    //cur1����cur2��ǰ�ڵ�С����ô��������һ�����׼����һ�αȽ�
		}
	}
	//�������2Ϊ�գ���ȫ�������ˣ��������1Ϊ�գ�����2��Ϊ�գ����ʣ�µķŵ�list1��
	if (cur2 != plist2->_head)                   //��cur1==plist1->head
	{
		tmp2 = plist2->_head->_prev;         //��¼plist2���һ�����
		cur2->_prev = cur1->_prev;           //cur2��pre����cur1��pre
		cur1->_prev->_next = cur2;          //cur1��pre��next����cur2��ָ��list��ǰ�ڵ㣩
		                                      //plist��cur2��β�ڵ㲻��Ҫ����
		tmp2->_next = cur1;                 //plist2��β�ڵ��next����list1��ͷ�ڵ�
		cur1->_prev = tmp2;                 //ͷ����pre����list2��β�ڵ�


	}

	free(plist2->_head);
}



//void ListXClassify(List* plist, LTDataType x)
//{
//
//	
//
//}

