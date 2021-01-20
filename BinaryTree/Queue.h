#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
#include"BinaryTree.h"

typedef BTNode* QDataType;

//���е�����
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

//���еĽṹ
typedef struct Queue
{
	QNode *_front;	//��ͷ
	QNode *_rear;	//��β
}Queue;

// ��ʼ������ 
void QueueInit(Queue* pq);
// ��β����� 
void QueuePush(Queue* pq, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* pq);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* pq);
// ���ٶ��� 
void QueueDestroy(Queue* pq);