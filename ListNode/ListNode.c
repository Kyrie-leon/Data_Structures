#include "ListNode.h"

//2.2 ��̬����һ���ڵ�
SListNode * BuyListNode(SLTDataType x)
{
	
	SListNode * plist=(SListNode *)malloc(sizeof(SListNode));
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

//2.5 ������ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	//�����½ڵ�
	SListNode * NewNode = BuyListNode(x);
	//�ж������Ƿ��
	if (*pplist == NULL)
	{
		//����Ϊ��ֱ�Ӳ���
		*pplist = NewNode;

	}
	else 
	{
		NewNode->next = *pplist;	//�½ڵ�nextָ��pplist
		*pplist=NewNode;			//����ͷ���
	}

}

//2.6 ������βɾ
void SListPopBack(SListNode** pplist)
{
	//1.������Ϊ��
	if (*pplist == NULL)
	{
		return;
	}
	//2.������ֻ��һ���ڵ�
	else if((*pplist)->next==NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.��������һ�����Ͻڵ�
	else
	{
		//taliָ���1���ڵ㣬prevΪ��
		SListNode * prev = NULL;
		SListNode * tail = *pplist;

		
		//���������ҵ�β�ڵ�
		while (tail->next!=NULL)
		{
			//ע���Ⱥ�˳��prev���߲Ų��ᶪʧ�ڵ�
			//prev�����һ���ڵ�
			prev = tail;
			//tail�����һ���ڵ�
			tail = tail->next;
		}
		//ɾ��β�ڵ�
		free(tail);
		//prev��Ϊ�µ�β�ڵ�
		prev->next = NULL;

	}
}

//2.7 ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	//1.�յ�����
	if (*pplist == NULL)
	{
		return;
	}
	//2.һ���ڵ�
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//3.һ������
	else
	{

		SListNode * phead = *pplist;
		//���ƶ�ɾ�����ͷ���
		*pplist = phead->next;
		//���ͷ�ԭ����ͷ���
		free(phead);
	}
}

//2.8 ���������
SListNode * SListFind(SListNode * plist, SLTDataType x)
{
	SListNode * cur = plist;
	//1.������ֱ�ӷ���
	//��������
	while (cur)
	{
		//����ҽڵ�ֵ����x�򷵻�
		if (x == cur->data)
		{
			return cur;
		}
		//û�ҵ���������
		cur = cur->next;
	}
	return NULL;
}

//2.9 ������������λ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//2.10 ������ɾ������λ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode * next = pos->next;	//�ҵ�posλ�ú���Ľڵ㱣����������ֹɾ����ʧ
		pos->next = next->next;			//posλ�ýڵ�ָ��next��Ľڵ�
		free(next);		//�ͷ�pos��Ľڵ�
	}
}