#include "List.h"


ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;

}

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* Head = BuyNode(0);
	Head->_next = Head->_prev = Head;
	return Head;
}


//˫����������������ͷ�ڵ�
void ListClear(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	//����ÿ���ڵ㲢�ͷ�
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pHead->_next = pHead->_prev = pHead;
}

// ˫����������
void ListDestory(ListNode** ppHead)
{
	assert(*ppHead);
	ListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	
	////����ÿ���ڵ㲢��ӡ
	while (cur != pHead)
	{
		ListNode* next = cur->_next;	//nextָ����һ���ڵ�
		printf("%d ", cur->_data);	//��ӡ��ǰ�ڵ�
		cur = next;		//curָ����һ���ڵ�
	}
	printf("\n");

}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead, x);

	//ListNode* tail = pHead->_prev;	//�ҵ�β�ڵ�
	//ListNode* newNode = BuyNode(x);	//����һ���½ڵ�
	//tail->_next = newNode;	//1.
	//newNode->_prev = tail;	//2.
	//newNode->_next = pHead;	//3.
	//pHead->_prev = newNode;	//4.
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_prev);

	//ListNode* tail = pHead->_prev;	//�ҵ�β�ڵ�
	//if (tail == pHead)	//ֻ��ͷ�ڵ�˵��˫������Ϊ�գ�ֱ�ӷ���
	//{
	//	return;
	//}
	//ListNode* prev = tail->_prev;	//β�ڵ��ǰһ���ڵ㣬���µ�β�ڵ�
	//free(tail);		//�ͷ�β�ڵ�
	//prev->_next = pHead;	//1.�µ�β�ڵ�nextָ��head
	//pHead->_prev = prev;	//2.head��prevָ���µ�β�ڵ�
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead->_next, x);


}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	
	ListErase(pHead->_next);


}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		if (cur->_data == x)
		{
			return cur;
		}
		cur = next;
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;	//pos��ǰһ�����
	ListNode* newNode = BuyNode(x);
	newNode->_prev = prev;	//1.
	prev->_next = newNode;	//2.
	pos->_prev = newNode;	//3.
	newNode->_next = pos;	//4.


}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;	//pos��ǰһ�����
	ListNode* next = pos->_next;	//pos�ĺ�һ���ڵ�
	
	free(pos);
	prev->_next = next;	//1.
	next->_prev = prev;	//2.

}