#ifndef _LISTNODE_H
#define _LISTNODE_H

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

//单链表的定义
typedef struct SListNode
{
	SLTDataType data;	//data
	struct SListNode * next; //next指向当前节点的下一个节点
}SListNode;


//动态申请一个节点
SListNode * BuyListNode(SLTDataType x);
//单链表打印
void SListPrint(SListNode * plist);
//单链表尾插
void SListPushBack(SListNode** pplist, SLTDataType x);
//单链表头插
void SListPushFront(SListNode** pplist, SLTDataType x);
//单链表尾删
void SListPopBack(SListNode** pplist);
//单链表头删
void SListPopFront(SListNode** pplist);
//单链表查找
SListNode * SListFind(SListNode * plist, SLTDataType x);
//单链表在任意位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDataType x);
//单链表删除任意位置之后的值
void SListEraseAfter(SListNode* pos);
//单链表的销毁
void SListDestory(SListNode* plist);


#endif