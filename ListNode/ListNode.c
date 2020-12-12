#include "ListNode.h"

//2.2 动态申请一个节点
SListNode * BuyListNode(SLTDataType x)
{
	
	SListNode * plist=(SListNode *)malloc(sizeof(SListNode));
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

//2.5 单链表头插
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	//申请新节点
	SListNode * NewNode = BuyListNode(x);
	//判断链表是否空
	if (*pplist == NULL)
	{
		//链表为空直接插入
		*pplist = NewNode;

	}
	else 
	{
		NewNode->next = *pplist;	//新节点next指向pplist
		*pplist=NewNode;			//更新头结点
	}

}

//2.6 单链表尾删
void SListPopBack(SListNode** pplist)
{
	//1.单链表为空
	if (*pplist == NULL)
	{
		return;
	}
	//2.单链表只有一个节点
	else if((*pplist)->next==NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.单链表有一个以上节点
	else
	{
		//tali指向第1个节点，prev为空
		SListNode * prev = NULL;
		SListNode * tail = *pplist;

		
		//遍历链表找到尾节点
		while (tail->next!=NULL)
		{
			//注意先后顺序，prev先走才不会丢失节点
			//prev向后走一个节点
			prev = tail;
			//tail向后走一个节点
			tail = tail->next;
		}
		//删除尾节点
		free(tail);
		//prev作为新的尾节点
		prev->next = NULL;

	}
}

//2.7 单链表头删
void SListPopFront(SListNode** pplist)
{
	//1.空单链表
	if (*pplist == NULL)
	{
		return;
	}
	//2.一个节点
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.一个以上
	else
	{

		SListNode * phead = *pplist;
		//现移动删除后的头结点
		*pplist = phead->next;
		//再释放原来的头结点
		free(phead);
	}
}

//2.8 单链表查找
SListNode * SListFind(SListNode * plist, SLTDataType x)
{
	SListNode * cur = plist;
	//1.空链表直接返回
	//遍历链表
	while (cur)
	{
		//如果找节点值等于x则返回
		if (x == cur->data)
		{
			return cur;
		}
		//没找到继续遍历
		cur = cur->next;
	}
	return NULL;
}

//2.9 单链表在任意位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//2.10 单链表删除任意位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode * next = pos->next;	//找到pos位置后面的节点保存起来，防止删除后丢失
		pos->next = next->next;			//pos位置节点指向next后的节点
		free(next);		//释放pos后的节点
	}
}