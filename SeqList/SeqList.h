#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define N 100
typedef int SLDataTpye;

////2.1.1顺序表的静态存储
//typedef struct SeqList
//{
//	SLDataTpye arr[N];	//定长数组
//	size_t size;	    //有效数组的个数
//}SL,SeqList;

//2.1.2 顺序表的动态存储
typedef struct SeqList
{
	SLDataTpye * array;	//指向动态开辟的数组
	size_t size;		//有效数据的个数
	size_t capacity;	//容量空间的大小
}SL, SeqList;

//顺序表基本增删查改接口功能函数声明


//顺序表的初始化
void SeqListInit(SeqList * psl);
//顺序表销毁
void SeqListDestory(SeqList * psl);
//顺序表打印
void SeqListPrint(SeqList * psl);
//检查空间，如果满了，进行增容
void CheckCapacity(SeqList * psl);


//顺序表尾插
void SeqListPushBack(SeqList * psl,SLDataTpye x);
//顺序表尾删
void SeqListPopBack(SeqList * psl);
//顺序表头插
void SeqListPushFront(SeqList * psl, SLDataTpye x);
//顺序表头删
void SeqListPopFront(SeqList * psl);


//顺序表查找
int SeqListFind(SeqList * psl, SLDataTpye x);
//顺序表在pos位置插入
void SeqListInsert(SeqList * psl, size_t pos, SLDataTpye x);
//顺序表删除pos位置的值
void SeqListErase(SeqList * psl, size_t pos);

#endif