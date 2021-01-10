#include"Heap.h"

//数据交换
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//堆向下调整算法
void AdjustDown(HPDataType* a, int n, int root)
{
	//1.首先确定父节点与孩子节点，默认孩子节点为左孩子
	int parent = root;
	int child = parent * 2 + 1;	//不区分左右孩子，默认左孩子为孩子节点	
	//遍历二叉树，当孩子节点超出数组范围则停止
	while (child < n)
	{
		//找出左右孩子中最小的节点作为孩子节点
		if ((child + 1 < n) && (a[child + 1] < a[child]))
		{
			child++;
		}

		//如果父亲节点大于孩子节点则交换，否则退出循环
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);	//交换
			parent = child;		//孩子节点作为新的父节点
			child = 2 * parent + 1;		//默认左孩子作为新的孩子节点
		}
		else
		{
			break;
		}
	}

}

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;	//新元素的父节点；
								//向上调整直到根节点
	while (child > 0)
	{
		//小根堆：如果父节点大于子节点就交换
		if (a[parent] >a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;		//父节点作为新的孩子节点
			parent = (child - 1) / 2;	//新的孩子节点的父节点
		}
		else
		{
			break;
		}
	}


}

//堆的创建
void HeapInit(Heap * php, HPDataType * a, int n)
{
	assert(php);

	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	//复制堆
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	
	//这种方法不够优化因此不采用
	//for (int i = n - 1; i >= 0; --i)
	//{
	//	AdjustDown(php->_a, n, i);
	//}

	//构建堆,从最后一个节点开始依次遍历执行向下调整算法，一直到根节点，可以找到最小的数
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, n, i);
	}
}

//堆的销毁
void HeapDestory(Heap* php)
{
	free(php->_a);		//先free堆中的数组
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}

//堆的插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	//堆满，重新申请空间
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;	//扩大2倍
		HPDataType *tmp = (HPDataType *)realloc(php->_a, sizeof(HPDataType)*php->_capacity);
		if (NULL == tmp)
		{
			printf("内存申请失败！\n");
			exit(-1);
		}
		php->_a = tmp;
	}
	

	php->_a[php->_size++] = x;	//元素插入数组末尾
	AdjustUp(php->_a, php->_size, php->_size - 1);
}


//堆的删除
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	//交换堆顶与最后一个数据
	swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;	//删除最后一个元素
	AdjustDown(php->_a, php->_size, 0);
}

//取堆顶的数据
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

//堆的数据个数
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

//堆的判空
int HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0;
}


//对数组进行堆排序
void HeapSort(HPDataType *a, int n)
{

	//1.构建堆,从最后一个节点开始依次遍历执行向下调整算法，一直到根节点，可以找到最小的数
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//每次和最后一个元素交换执行向下调整
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

//堆打印
void HeapPrint(HPDataType *a, int n)
{
	assert(a);
	assert(n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void PrintTopK(int* a, int n, int k)
{
	assert(a);

	Heap hp;
	//先建K个堆,小根堆
	HeapInit(&hp, a, k);
	//让数组中k后面的每个数和堆顶比较
	int start = k;
	while (start < n)
	{
		if (a[start] > hp._a[0])	//只要大于堆顶的数就交换，执行向下调整算法
		{
			hp._a[0] = a[start];
			AdjustDown(hp._a, k, 0);
		}
		++start;
	}
	HeapPrint(hp._a, k);

}