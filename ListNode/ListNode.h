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
	SLTDataType data;
	SListNode * next; //nextָ��ǰ�ڵ����һ���ڵ�
}SListNode;


//��̬����һ���ڵ�
SListNode * BuyListNode(SLTDataType x);
//�������ӡ

//������ͷ��
//������β��
//������ͷɾ
//������βɾ
//���������
//������������λ��֮�����x
//������ɾ������λ��֮���ֵ
#endif