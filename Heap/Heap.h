#pragma once
#include<stdio.h>

//���ʵ��
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;	
	int _size;		//������ЧԪ�ظ���
	int _capacity;	//������
}Heap;

void HeapInit(Heap * php, HPDataType * a, int n);
