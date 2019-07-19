#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

void SListInit(SListNode** pphead)
{
	
	*pphead = NULL;

}
SListNode* BuySListNode(SLTDataType x)           //��һ���µĽ��
{
	SListNode* tmp = (SListNode *)malloc(sizeof(SListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}
void SListEraseAfter(SListNode* pos)  //ɾ��pos������Ľڵ�
{
	SListNode* tmp = pos->_next;      //-> �н����ö�Ӧ�����[],ȡֵ��ĵ�
	if (tmp == NULL)                   //������Ϊ���һ���ڵ㣬��ɾ��
	{
		return;
	}
	pos->_next = tmp->_next;
	free(tmp);                         //�ͷŵ�ַ����tmp�Ŀռ�
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

void SListPushFront(SListNode** pphead, SLTDataType x)   //ͷ�壬ͷ�ڵ�ĵ�ַҪ�� ������Ҫ����ͷ�ڵ��ַ�����ĵ�ַ�����ܸı�ͷ�ڵ��ַ��ֵ 
{
	SListNode* tmp;
	tmp = BuySListNode(x);
	tmp->_next = *pphead;                               //ͷ��ṹ���nextҪָ��ԭ����һ���ṹ��
	*pphead = tmp;                                       //ͷ�ڵ�������ڵ�һ��Ԫ�صĵ�ַ
}
void SListPopFront(SListNode**  pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->_next;       //tmp����ԭ��һ���ڵ��next��ԭ�ڵ����һ���ڵ�ĵ�ַ
	free(*pphead);
	*pphead = tmp;

}
SListNode* SListFind(SListNode* phead, SLTDataType x)//����
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			return tmp;                        //����dataΪx�ĵ�ַ����������һ���ڵ��У�forѭ����tmp��������һ���ڵ��nextֵ�����x�Ľṹ��ĵ�ַ��
		}
	}
	return NULL;
}
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);      //tmp�����½��ڵ�ĵ�ַ 
	tmp->_next = pos->_next;
	pos->_next = tmp;



}
// ��pos��ǰ����в���


void SListRemove(SListNode** pphead, SLTDataType x)   //�������ֵΪx��ֵ
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







void SListAllRemove(SListNode** pphead, SLTDataType x)   //�������ֵΪx��ֵ
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

//�������򣡣�������������������������������*****************************���ִ����ص�ѽ����������������������������������
void SListReverse1(SListNode** pphead)
{
	SListNode* head = *pphead;                 //��ÿ��ѭ���У�ʼ��ָ��������ͷ
	SListNode* tmp = (*pphead)->_next;         //��ÿ��ѭ���У�ʼ��ָ��Ҫ��βɾ�Ľڵ�
	SListNode* oldh = *pphead;                 //��ÿ��ѭ���У�ָ��ԭ����ͷ��
	while (tmp)                               //tmpΪ�գ����������������ͷ��nextΪ�գ�˵�����Ѿ���β����
	{
		oldh->_next = tmp->_next;              //��ɾ����
		tmp->_next = head;                     //��tmp����µ�ͷ��ͷ�����
		head = tmp;                            //��ͷ���ڵ�
		tmp = oldh->_next;                      //��tmp������һ��Ҫɾ���Ľ��
	} 
	*pphead = head;
	




}
void SListReverse2(SListNode** pphead)
{
	SListNode* pre = *pphead;                 //��ִ�в�����ǰһ���ڵ�
	SListNode* cur = pre->_next;         //��ִ�в����Ľڵ�
	SListNode* next = cur;                 //��ִ�в����ĺ�һ���ڵ�
	pre->_next = NULL;                     //ͷ�������β�ڵ�
	while (next)
	{
		next = next->_next;               //��ѭ����ʼʱ��������һ���ڵ㣬֮���Բ�����֮ǰ��ֵ������Ϊ���������next�����
		cur->_next = pre;                    //��ԭ����_nextָ��ǰ����
		pre = cur;                           //������һ��ѭ����pre�ڵ�
		cur = next;                          //������һ��ѭ����cur�ڵ�

	}
	*pphead = pre;                        //����ѭ����cur��next���Ѿ�ָ����ˣ�pre����ͷ

}
//�Ҷ���˼�룬�ó��������߼�������һ������ʱ��Ƚϡ��Ƚ� ��ʱ��Ƚϵ�ַ������������
SListNode* SListFindCommenNode(SListNode* phead1, SListNode*phead2)
{
	int len1 = 0;
	int len2 = 0;

	int gap,i;
	SListNode* cur;
	SListNode* longlist=phead1;
	SListNode* shortlist=phead2;
	for (cur=phead1; cur; cur = cur->_next)
	{
		len1++;
	}
	for (cur = phead2; cur; cur = cur->_next)
	{
		len2++;
	}
	gap = abs(len1 - len2);
	if (len1 < len2)
	{
		longlist = phead2;
		shortlist = phead1;
	}
	for (i = 0; i < gap;i++ )
	{
		longlist = longlist->_next;
	}
	for (; longlist && shortlist; longlist = longlist->_next, shortlist = shortlist->_next)
	{
		if (longlist == shortlist)
		{
			return longlist;
		}
	}
	return NULL;
}

int exitCycle(SListNode* phead)
{
	SListNode*  fast = phead;
	SListNode*  slow = phead;
	while (fast &&slow&&fast->_next)  //������fast-->next->next
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast&&fast->_next)         //fastû�������꣬����û�н�β��
	{
		return  1;
	}
	else return 0;




}

SListNode * detectCycle(SListNode* head)
{
	SListNode*  fast=head;
	SListNode*slow=head;

	while (fast &&slow&&fast->_next)  //������fast-->next->next
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
		{
			break;
		}
	}
	for (; fast&&fast->_next; fast = fast->_next, head = head->_next)
	{
		if (head == fast)
		{
			return head;
		}
	}
	return NULL;


}
