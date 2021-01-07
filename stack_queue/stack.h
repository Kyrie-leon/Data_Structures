#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>

#define N 10
typedef int STDataType;
typedef struct Stack Stack;
//struct Stack
//{
//	STDataType a[N];
//	int _top;	//ջ��
//};

//֧�ֶ�̬������ջ
struct Stack
{
	STDataType * _a;
	int _top;			//ջ��
	int _capacity;		//����
};

//��ʼ��ջ
void StackInit(Stack * ps);

//��ջ
void StackPush(Stack * ps, STDataType data);

//��ջ
void StackPop(Stack * ps);

//��ȡջ��Ԫ��
STDataType StackTop(Stack *ps);

//��ȡջ������ЧԪ�ظ���
int StackSize(Stack * ps);

//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط�0����Ϊ�շ���0
int StackEmpty(Stack* ps);

//����ջ
void StackDestory(Stack * ps);
