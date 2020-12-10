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


}

int main()
{
	TestListNode1();
	system("pause");
	return 0;
}