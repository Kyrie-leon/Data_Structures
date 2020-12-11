#ifndef _LISTNODE_H
#define _LISTNODE_H

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

//������Ķ���
typedef struct SListNode
{
	SLTDataType data;	//data
	struct SListNode * next; //nextָ��ǰ�ڵ����һ���ڵ�
}SListNode;


//��̬����һ���ڵ�
SListNode * BuyListNode(SLTDataType x);
//�������ӡ
void SListPrint(SListNode * plist);
//������β��
void SListPushBack(SListNode** pplist, SLTDataType x);
//������ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x);
//������βɾ
void SListPopBack(SListNode** pplist);
//������ͷɾ
void SListPopFront(SListNode** pplist);
//���������
SListNode * SListFind(SListNode * plist, SLTDataType x);
//������������λ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDataType x);
//������ɾ������λ��֮���ֵ
void SListEraseAfter(SListNode* pos);
//�����������
void SListDestory(SListNode* plist);


#endif