#include"Heap.h"

//���ݽ���
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ǰ�᣺������������С��
void AdjustDown(HPDataType* a, int n, int root)
{
	//�ҳ����Һ���С����һ��
	int parent = root;
	int child = parent * 2 + 1;	//����
	
	while (child < n)
	{
		//�ҳ����Һ���С����һ��
		if (child+1<n && a[child + 1] < a[child])
		{
			++child;
		}

		//С�����ϸ�
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
	//���ƶ�
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//������


}