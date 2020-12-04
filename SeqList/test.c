#include "SeqList.h"

//����ͷβ����ɾ��
void TestSeqList1()
{
	//���ȶ���һ��˳���
	SeqList s;
	//˳����ʼ���ӿڲ���
	SeqListInit(&s);
	//˳���β��βɾ�ӿڲ���
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//ͷ��ͷɾ�ӿڲ���
	//SeqListPushFront(&s, -1);
	//SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//���ҽӿڲ���
	printf("%d\n",SeqListFind(&s, 4));
	//����λ�ò���ӿڲ���
	SeqListInsert(&s, 3, 30);
	SeqListPrint(&s);

	//����λ��ɾ��
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	//˳�������
	SeqListDestory(&s);


}


int main()
{
	TestSeqList1();

	return 0;
}