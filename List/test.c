#include"List.h"

void TestList()
{
	ListNode *p;
	p = ListCreate();
	ListPushFront(p, 5);
	ListPushFront(p, 4);
	ListPushFront(p, 3);
	ListPushFront(p, 2);
	ListPushFront(p, 1);
	ListPrint(p);

	ListPopFront(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPrint(p);

	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPushBack(p, 5);
	ListPrint(p);

	ListPopBack(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPrint(p);


	//ListDestory(&p);

	ListPushFront(p, 5);
	ListPushFront(p, 4);
	ListPushFront(p, 3);
	ListPushFront(p, 2);
	ListPushFront(p, 1);
	ListPrint(p);

	ListNode* pos = ListFind(p, 3);
	pos->_data = 30;
	ListPrint(p);

	ListInsert(pos, 33);
	ListPrint(p);
	ListErase(pos);
	ListPrint(p);

	ListDestory(&p);
}

int main()
{
	TestList();
	system("pause");
	return 0;
}