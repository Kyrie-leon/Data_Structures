#pragma once
#include<stdio.h>

//¥Û∂— µœ÷
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap * php, HPDataType * a, int n);
