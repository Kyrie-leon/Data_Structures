#include "ListNode.h"

//2.2 动态申请一个节点
SListNode * BuyListNode(SLTDataType x)
{
	
	SListNode * plist=(SLTDataType *)malloc(sizeof(SLTDataType));
	//判断申请是否成功
	if (plist==NULL)
	{
		printf("申请新节点失败\n");
		exit(-1);
	}
	plist->data = x;
	plist->next = NULL;
	return plist;
}

//2.3 单链表打印
void SListPrint(SListNode * plist)
{

	//打印链表
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;	//节点指向下一个
	}
	printf("NULL\n");
}

//2.4 单链表尾插
void SListPushBack(SListNode** pplist, SLTDataType x)
{
	//申请一个新节点
	SListNode* NewNode = BuyListNode(x);

	//判断链表是否为空，如果为空则申请节点直接插入，否则找到尾节点插入
	if ((*pplist) == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		//定义一个当前节点tail去找链表的尾节点
		SListNode* tail = *pplist;

		//遍历节点找尾节点
		while (tail->next)
		{
			tail = tail->next;
		}

		//尾节点的next指向新节点
		tail->next = NewNode;
	}

}
