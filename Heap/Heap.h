#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//大堆实现
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;	
	int _size;		//堆中有效元素个数
	int _capacity;	//堆容量
}Heap;

//堆的创建
void HeapInit(Heap * php, HPDataType * a, int n);

//堆的销毁
void HeapDestory(Heap* php);

//堆的插入
void HeapPush(Heap* php, HPDataType x);

//堆的删除
void HeapPop(Heap* php);

//取堆顶的数据
HPDataType HeapTop(Heap* php);

//堆的数据个数
int HeapSize(Heap* php);

//堆的判空
int HeapEmpty(Heap* php);

//对数组进行堆排序
void HeapSort(HPDataType *a, int n);

//堆打印
void HeapPrint(HPDataType *php, int n);