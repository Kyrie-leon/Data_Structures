#include "List.h"


ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;

}

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* Head = BuyNode(0);
	Head->_next = Head->_prev = Head;
	return Head;
}


//双向链表的清除，保留头节点
void ListClear(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	//遍历每个节点并释放
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pHead->_next = pHead->_prev = pHead;
}

// 双向链表销毁
void ListDestory(ListNode** ppHead)
{
	assert(*ppHead);
	ListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;
	
	////遍历每个节点并打印
	while (cur != pHead)
	{
		ListNode* next = cur->_next;	//next指向下一个节点
		printf("%d ", cur->_data);	//打印当前节点
		cur = next;		//cur指向下一个节点
	}
	printf("\n");

}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead, x);

	//ListNode* tail = pHead->_prev;	//找到尾节点
	//ListNode* newNode = BuyNode(x);	//创建一个新节点
	//tail->_next = newNode;	//1.
	//newNode->_prev = tail;	//2.
	//newNode->_next = pHead;	//3.
	//pHead->_prev = newNode;	//4.
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListErase(pHead->_prev);

	//ListNode* tail = pHead->_prev;	//找到尾节点
	//if (tail == pHead)	//只有头节点说明双向链表为空，直接返回
	//{
	//	return;
	//}
	//ListNode* prev = tail->_prev;	//尾节点的前一个节点，即新的尾节点
	//free(tail);		//释放尾节点
	//prev->_next = pHead;	//1.新的尾节点next指向head
	//pHead->_prev = prev;	//2.head的prev指向新的尾节点
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListInsert(pHead->_next, x);


}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	
	ListErase(pHead->_next);


}

// 双向链表查找
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
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;	//pos的前一个结点
	ListNode* newNode = BuyNode(x);
	newNode->_prev = prev;	//1.
	prev->_next = newNode;	//2.
	pos->_prev = newNode;	//3.
	newNode->_next = pos;	//4.


}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;	//pos的前一个结点
	ListNode* next = pos->_next;	//pos的后一个节点
	
	free(pos);
	prev->_next = next;	//1.
	next->_prev = prev;	//2.

}