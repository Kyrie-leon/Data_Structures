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
	SLTDataType data;
	SListNode * next; //next指向当前节点的下一个节点
}SListNode;


//动态申请一个节点
SListNode * BuyListNode(SLTDataType x);
//单链表打印

//单链表头插
//单链表尾插
//单链表头删
//单链表尾删
//单链表查找
//单链表在任意位置之后插入x
//单链表删除任意位置之后的值
#endif