#include "SeqList.h"


//2.2 顺序表初始化
void SeqListInit(SeqList * psl)
{
	//开辟的大小随机给值
	psl->array = (SLDataTpye *)malloc(sizeof(SLDataTpye) * 4);
	if (psl->array == NULL)
	{
		printf("初始化失败\n");
		exit(-1);
	}

	psl->size = 0;	//有效数据为0
	psl->capacity = 4;	//容量空间大小为4
}

//2.3 顺序表增容
//检查空间，如果满了，进行增容
void CheckCapacity(SeqList * psl)
{
	//有效数据与容量空间相等代表空间满了，需要增容！
	if (psl->size == psl->capacity)
	{
		//对顺序表容量扩大两倍
		psl->capacity *= 2;
		//使用realloc扩展空间
		psl->array = (SLDataTpye *)realloc(psl->array, sizeof(SLDataTpye)*psl->capacity);

		//判断下是否申请失败
		if (psl->array == NULL)
		{
			printf("增容失败\n");
			exit(-1);
		}
	}
}

//2.4 顺序表打印
void SeqListPrint(SeqList * psl)
{
	//判断指针合法性
	assert(psl);

	//依次遍历顺序表每个节点，并打印节点中的元素值
	for (size_t i = 0; i < psl->size; ++i)
	{
		printf("%d ", i, psl->array[i]);
	}
	printf("\n");

}

//2.5 顺序表尾插
void SeqListPushBack(SeqList * psl, SLDataTpye x)
{
	//判断指针合法性
	assert(psl);
	//检查空间，如果满了，进行增容
	CheckCapacity(psl);

	psl->array[psl->size] = x;	//将数据x插入到线性表末尾
	psl->size++;	//有效数据加1
}

//2.6 顺序表尾删
void SeqListPopBack(SeqList * psl)
{
	//判断指针合法性
	assert(psl);

	//有效数据-1
	psl->size--;
}

//2.7 顺序表头插
void SeqListPushFront(SeqList * psl, SLDataTpye x)
{
	//判断指针合法性
	assert(psl);
	//检查空间，如果满了，进行增容
	CheckCapacity(psl);

	//头插从后往前拷贝
	int end = psl->size - 1;	//指向最后一个节点
	while(end >= 0)
	{
		psl->array[end + 1] = psl->array[end];	//节点向后移动一个位置
		--end;
	}

	
	psl->array[0] = x;	//插入元素x
	psl->size++;	//有效数据+1

}

//2.8 顺序表头删
void SeqListPopFront(SeqList * psl)
{
	//判断指针合法性
	assert(psl);


	size_t start = 0;	//指向第一个节点
	while (start < psl->size-1)
	{
		psl->array[start] = psl->array[start+1];
		++start;
	}

	psl->size--;	//有效数据-1
}

//2.9 顺序表查找
int SeqListFind(SeqList * psl, SLDataTpye x)
{
	//判断指针合法性
	assert(psl);

	//从第一个节点开始查找，如果找到就返回该位置的值
	size_t start = 0;
	while (start < psl->size)
	{
		if (x == psl->array[start])
		{
			return start + 1;
		}
		start++;
	}

	//没有找到返回-1
	return -1;
}


//2.10 顺序表在pos位置插入
void SeqListInsert(SeqList * psl, size_t pos, SLDataTpye x)
{
	//判断指针合法性
	assert(psl);
	//判断位置的合法性
	assert(pos >= 0 || pos <= psl->size);

	//检查空间，如果满了，进行增容
	CheckCapacity(psl);

	//end指向最后一个位置
	size_t end = psl->size - 1;
	//将pos位置的节点分别向后移动一个位置
	while (end >= pos - 1)
	{
		psl->array[end + 1] = psl->array[end];
		--end;
	}

	psl->array[pos - 1] = x;	//将x插入到第pos个位置
	psl->size++;	//有效数据+1

}


//2.11 顺序表删除pos位置的值
void SeqListErase(SeqList * psl, size_t pos)
{
	//判断指针合法性
	assert(psl);

	size_t start = pos-1;	//指向要删除的位置
	while (start < psl->size-1)
	{
		psl->array[start] = psl->array[start + 1];
		++start;
	}

	psl->size--;	//有效数据-1
}

//2.12 顺序表销毁
void SeqListDestory(SeqList * psl)
{
	//判断指针合法性
	assert(psl);

	//销毁顺序表
	free(psl->array);
	psl->array = NULL;
	psl->size = 0;
	psl->capacity = 0;

}