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

	//2.5 ������ͷ��
	SListPushFront(&Plist, -1);
	SListPrint(Plist);

	//������βɾ
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

	//////������ͷɾ
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPopFront(&Plist);
	//SListPrint(Plist);

	//2.8 ���������
	SListNode * pos = SListFind(Plist, 3);
	SListPrint(pos);

	//2.9 ������������λ��֮�����x
	SListInsertAfter(pos, 30);
	SListPrint(Plist);

	//2.10 ������ɾ������λ��֮���ֵ
	SListEraseAfter(pos);
	SListPrint(Plist);


}



int main()
{
	TestListNode1();
	system("pause");
	return 0;
}