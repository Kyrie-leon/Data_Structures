#include "ListNode.h"

//2.2 ��̬����һ���ڵ�
SListNode * BuyListNode(SLTDataType x)
{
	
	SListNode * plist=(SLTDataType *)malloc(sizeof(SLTDataType));
	//�ж������Ƿ�ɹ�
	if (plist==NULL)
	{
		printf("�����½ڵ�ʧ��\n");
		exit(-1);
	}
	plist->data = x;
	plist->next = NULL;
	return plist;
}

//2.3 �������ӡ
void SListPrint(SListNode * plist)
{

	//��ӡ����
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;	//�ڵ�ָ����һ��
	}
	printf("NULL\n");
}

//2.4 ������β��
void SListPushBack(SListNode** pplist, SLTDataType x)
{
	//����һ���½ڵ�
	SListNode* NewNode = BuyListNode(x);

	//�ж������Ƿ�Ϊ�գ����Ϊ��������ڵ�ֱ�Ӳ��룬�����ҵ�β�ڵ����
	if ((*pplist) == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		//����һ����ǰ�ڵ�tailȥ�������β�ڵ�
		SListNode* tail = *pplist;

		//�����ڵ���β�ڵ�
		while (tail->next)
		{
			tail = tail->next;
		}

		//β�ڵ��nextָ���½ڵ�
		tail->next = NewNode;
	}

}
