#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//���ʵ��
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;	
	int _size;		//������ЧԪ�ظ���
	int _capacity;	//������
}Heap;

//�ѵĴ���
void HeapInit(Heap * php, HPDataType * a, int n);

//�ѵ�����
void HeapDestory(Heap* php);

//�ѵĲ���
void HeapPush(Heap* php, HPDataType x);

//�ѵ�ɾ��
void HeapPop(Heap* php);

//ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);

//�ѵ����ݸ���
int HeapSize(Heap* php);

//�ѵ��п�
int HeapEmpty(Heap* php);

//��������ж�����
void HeapSort(HPDataType *a, int n);

//�Ѵ�ӡ
void HeapPrint(HPDataType *php, int n);