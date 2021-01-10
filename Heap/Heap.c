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
	int child = parent * 2 + 1;	//���������Һ��ӣ�Ĭ������Ϊ���ӽڵ�	
	//�����������������ӽڵ㳬�����鷶Χ��ֹͣ
	while (child < n)
	{
		//�ҳ����Һ�������С�Ľڵ���Ϊ���ӽڵ�
		if ((child + 1 < n) && (a[child + 1] < a[child]))
		{
			child++;
		}

		//������׽ڵ���ں��ӽڵ��򽻻��������˳�ѭ��
		if (a[parent] > a[child])
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

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;	//��Ԫ�صĸ��ڵ㣻
								//���ϵ���ֱ�����ڵ�
	while (child > 0)
	{
		//С���ѣ�������ڵ�����ӽڵ�ͽ���
		if (a[parent] >a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;		//���ڵ���Ϊ�µĺ��ӽڵ�
			parent = (child - 1) / 2;	//�µĺ��ӽڵ�ĸ��ڵ�
		}
		else
		{
			break;
		}
	}


}

//�ѵĴ���
void HeapInit(Heap * php, HPDataType * a, int n)
{
	assert(php);

	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	//���ƶ�
	memcpy(php->_a, a, sizeof(HPDataType)*n);
	php->_size = n;
	php->_capacity = n;
	
	//���ַ��������Ż���˲�����
	//for (int i = n - 1; i >= 0; --i)
	//{
	//	AdjustDown(php->_a, n, i);
	//}

	//������,�����һ���ڵ㿪ʼ���α���ִ�����µ����㷨��һֱ�����ڵ㣬�����ҵ���С����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, n, i);
	}
}

//�ѵ�����
void HeapDestory(Heap* php)
{
	free(php->_a);		//��free���е�����
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}

//�ѵĲ���
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	//��������������ռ�
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;	//����2��
		HPDataType *tmp = (HPDataType *)realloc(php->_a, sizeof(HPDataType)*php->_capacity);
		if (NULL == tmp)
		{
			printf("�ڴ�����ʧ�ܣ�\n");
			exit(-1);
		}
		php->_a = tmp;
	}
	

	php->_a[php->_size++] = x;	//Ԫ�ز�������ĩβ
	AdjustUp(php->_a, php->_size, php->_size - 1);
}


//�ѵ�ɾ��
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	//�����Ѷ������һ������
	swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;	//ɾ�����һ��Ԫ��
	AdjustDown(php->_a, php->_size, 0);
}

//ȡ�Ѷ�������
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

//�ѵ����ݸ���
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

//�ѵ��п�
int HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0;
}


//��������ж�����
void HeapSort(HPDataType *a, int n)
{

	//1.������,�����һ���ڵ㿪ʼ���α���ִ�����µ����㷨��һֱ�����ڵ㣬�����ҵ���С����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//ÿ�κ����һ��Ԫ�ؽ���ִ�����µ���
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

//�Ѵ�ӡ
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
	//�Ƚ�K����,С����
	HeapInit(&hp, a, k);
	//��������k�����ÿ�����ͶѶ��Ƚ�
	int start = k;
	while (start < n)
	{
		if (a[start] > hp._a[0])	//ֻҪ���ڶѶ������ͽ�����ִ�����µ����㷨
		{
			hp._a[0] = a[start];
			AdjustDown(hp._a, k, 0);
		}
		++start;
	}
	HeapPrint(hp._a, k);

}