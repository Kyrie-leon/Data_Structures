#pragma once
#include<stdio.h>

//大堆实现
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;	
	int _size;		//堆中有效元素个数
	int _capacity;	//堆容量
}Heap;

void HeapInit(Heap * php, HPDataType * a, int n);
