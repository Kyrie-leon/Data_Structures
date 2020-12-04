#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define N 100
typedef int SLDataTpye;

////2.1.1˳���ľ�̬�洢
//typedef struct SeqList
//{
//	SLDataTpye arr[N];	//��������
//	size_t size;	    //��Ч����ĸ���
//}SL,SeqList;

//2.1.2 ˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataTpye * array;	//ָ��̬���ٵ�����
	size_t size;		//��Ч���ݵĸ���
	size_t capacity;	//�����ռ�Ĵ�С
}SL, SeqList;

//˳��������ɾ��Ľӿڹ��ܺ�������


//˳���ĳ�ʼ��
void SeqListInit(SeqList * psl);
//˳�������
void SeqListDestory(SeqList * psl);
//˳����ӡ
void SeqListPrint(SeqList * psl);
//���ռ䣬������ˣ���������
void CheckCapacity(SeqList * psl);


//˳���β��
void SeqListPushBack(SeqList * psl,SLDataTpye x);
//˳���βɾ
void SeqListPopBack(SeqList * psl);
//˳���ͷ��
void SeqListPushFront(SeqList * psl, SLDataTpye x);
//˳���ͷɾ
void SeqListPopFront(SeqList * psl);


//˳������
int SeqListFind(SeqList * psl, SLDataTpye x);
//˳�����posλ�ò���
void SeqListInsert(SeqList * psl, size_t pos, SLDataTpye x);
//˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList * psl, size_t pos);

#endif