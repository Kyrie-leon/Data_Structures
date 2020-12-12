#include "ListNode.h"


//测试单链表的头尾删除
void TestListNode1()
{
	SListNode * Plist=NULL;	//定义一个单链表

	//测试申请一个节点
	Plist = BuyListNode(1);

	//打印链表测试
	SListPrint(Plist);

	//2.4 单链表尾插测试
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 5);
	SListPrint(Plist);

	//2.5 单链表头插
	SListPushFront(&Plist, -1);
	SListPrint(Plist);

	//单链表尾删
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);
	//SListPopBack(&Plist);	
	//SListPopBack(&Plist);	
	//SListPopBack(&Plist);
	//SListPrint(Plist);

	//////单链表头删
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPrint(Plist);

	//2.8 单链表查找
	SListNode * pos = SListFind(Plist, 3);
	SListPrint(pos);

	//2.9 单链表在任意位置之后插入x
	SListInsertAfter(pos, 30);
	SListPrint(Plist);

	//2.10 单链表删除任意位置之后的值
	SListEraseAfter(pos);
	SListPrint(Plist);


}



int main()
{
	TestListNode1();
	system("pause");
	return 0;
}