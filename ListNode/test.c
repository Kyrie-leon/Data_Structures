#include "ListNode.h"


//���Ե������ͷβɾ��
void TestListNode1()
{
	SListNode * Plist=NULL;	//����һ��������

	//��������һ���ڵ�
	Plist = BuyListNode(1);

	//��ӡ�������
	SListPrint(Plist);

	//2.4 ������β�����
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