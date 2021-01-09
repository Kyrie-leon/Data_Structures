#include"Heap.h"

//���ݽ���
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//�����µ����㷨
void AdjustDown(HPDataType* a, int n, int root)
{
	//1.����ȷ�����ڵ��뺢�ӽڵ㣬Ĭ�Ϻ��ӽڵ�Ϊ����
	int parent = root;
	int child = parent * 2 + 1;
	//�����������������ӽڵ㳬�����鷶Χ��ֹͣ
	while (child < n)
	{
		//�ҳ����Һ�������С�Ľڵ���Ϊ���ӽڵ�
		if ((child + 1 < n) && (a[child + 1] < a[child]))
		{
			child++;
		}

		//������׽ڵ���ں��ӽڵ��򽻻��������˳�ѭ��
		if ((child + 1 < n) && (a[parent] > a[child]))
		{
			swap(&a[parent], &a[child]);	//����
			parent = child;		//���ӽڵ���Ϊ�µĸ��ڵ�
			child = 2 * parent + 1;		//Ĭ��������Ϊ�µĺ��ӽڵ�
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
	//���ƶ�
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//������


}


