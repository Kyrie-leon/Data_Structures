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
	int child = parent * 2 + 1;
	//遍历二叉树，当孩子节点超出数组范围则停止
	while (child < n)
	{
		//找出左右孩子中最小的节点作为孩子节点
		if ((child + 1 < n) && (a[child + 1] < a[child]))
		{
			child++;
		}

		//如果父亲节点大于孩子节点则交换，否则退出循环
		if ((child + 1 < n) && (a[parent] > a[child]))
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

void HeapInit(Heap * php, HPDataType * a, int n)
{
	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	//复制堆
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//构建堆


}


