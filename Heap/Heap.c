#include"Heap.h"

//数据交换
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//前提：左右子树都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{
	//找出左右孩子小的哪一个
	int parent = root;
	int child = parent * 2 + 1;	//左孩子
	
	while (child < n)
	{
		//找出左右孩子小的那一个
		if (child+1<n && a[child + 1] < a[child])
		{
			++child;
		}

		//小数据上浮
		if (a[child] < a[parent])
		{
			swap(a[child],a[parent]);
			parent++;
		}

	}
}

void HeapInit(Heap * php, HPDataType * a, int n)
{
	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	//复制堆
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//构建堆


}