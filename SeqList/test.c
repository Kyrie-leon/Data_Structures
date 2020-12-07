#include "SeqList.h"

//����ͷβ����ɾ��
void TestSeqList1()
{
	//���ȶ���һ��˳���
	SeqList s;
	//˳����ʼ���ӿڲ���
	SeqListInit(&s);
	//˳���β��ӿڲ���
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPrint(&s);

	//˳���ͷ��ӿڲ���
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);

	//ͷ��ͷɾ�ӿڲ���
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//���ҽӿڲ���
	////printf("%d\n",SeqListFind(&s, 4));

	//����λ�ò���ӿڲ���
	SeqListInsert(&s, 2, 30);
	SeqListPrint(&s);

	////����λ��ɾ��
	//SeqListErase(&s, 3);
	//SeqListPrint(&s);

	////˳�������
	//SeqListDestory(&s);


}


int main()
{
	TestSeqList1();

	return 0;
}