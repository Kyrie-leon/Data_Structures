#include "SeqList.h"


//2.2 ˳����ʼ��
void SeqListInit(SeqList * psl)
{
	//���ٵĴ�С�����ֵ
	psl->array = (SLDataTpye *)malloc(sizeof(SLDataTpye) * 4);
	if (psl->array == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(-1);
	}

	psl->size = 0;	//��Ч����Ϊ0
	psl->capacity = 4;	//�����ռ��СΪ4
}

//2.3 ˳�������
//���ռ䣬������ˣ���������
void CheckCapacity(SeqList * psl)
{
	//��Ч�����������ռ���ȴ���ռ����ˣ���Ҫ���ݣ�
	if (psl->size == psl->capacity)
	{
		//��˳���������������
		psl->capacity *= 2;
		//ʹ��realloc��չ�ռ�
		psl->array = (SLDataTpye *)realloc(psl->array, sizeof(SLDataTpye)*psl->capacity);

		//�ж����Ƿ�����ʧ��
		if (psl->array == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

//2.4 ˳����ӡ
void SeqListPrint(SeqList * psl)
{
	//�ж�ָ��Ϸ���
	assert(psl);

	//���α���˳���ÿ���ڵ㣬����ӡ�ڵ��е�Ԫ��ֵ
	for (size_t i = 0; i < psl->size; ++i)
	{
		printf("%d ", i, psl->array[i]);
	}
	printf("\n");

}

//2.5 ˳���β��
void SeqListPushBack(SeqList * psl, SLDataTpye x)
{
	//�ж�ָ��Ϸ���
	assert(psl);
	//���ռ䣬������ˣ���������
	CheckCapacity(psl);

	psl->array[psl->size] = x;	//������x���뵽���Ա�ĩβ
	psl->size++;	//��Ч���ݼ�1
}

//2.6 ˳���βɾ
void SeqListPopBack(SeqList * psl)
{
	//�ж�ָ��Ϸ���
	assert(psl);

	//��Ч����-1
	psl->size--;
}

//2.7 ˳���ͷ��
void SeqListPushFront(SeqList * psl, SLDataTpye x)
{
	//�ж�ָ��Ϸ���
	assert(psl);
	//���ռ䣬������ˣ���������
	CheckCapacity(psl);

	//ͷ��Ӻ���ǰ����
	int end = psl->size - 1;	//ָ�����һ���ڵ�
	while(end >= 0)
	{
		psl->array[end + 1] = psl->array[end];	//�ڵ�����ƶ�һ��λ��
		--end;
	}

	
	psl->array[0] = x;	//����Ԫ��x
	psl->size++;	//��Ч����+1

}

//2.8 ˳���ͷɾ
void SeqListPopFront(SeqList * psl)
{
	//�ж�ָ��Ϸ���
	assert(psl);


	size_t start = 0;	//ָ���һ���ڵ�
	while (start < psl->size-1)
	{
		psl->array[start] = psl->array[start+1];
		++start;
	}

	psl->size--;	//��Ч����-1
}

//2.9 ˳������
int SeqListFind(SeqList * psl, SLDataTpye x)
{
	//�ж�ָ��Ϸ���
	assert(psl);

	//�ӵ�һ���ڵ㿪ʼ���ң�����ҵ��ͷ��ظ�λ�õ�ֵ
	size_t start = 0;
	while (start < psl->size)
	{
		if (x == psl->array[start])
		{
			return start + 1;
		}
		start++;
	}

	//û���ҵ�����-1
	return -1;
}


//2.10 ˳�����posλ�ò���
void SeqListInsert(SeqList * psl, size_t pos, SLDataTpye x)
{
	//�ж�ָ��Ϸ���
	assert(psl);
	//�ж�λ�õĺϷ���
	assert(pos >= 0 || pos <= psl->size);

	//���ռ䣬������ˣ���������
	CheckCapacity(psl);

	//endָ�����һ��λ��
	size_t end = psl->size - 1;
	//��posλ�õĽڵ�ֱ�����ƶ�һ��λ��
	while (end >= pos - 1)
	{
		psl->array[end + 1] = psl->array[end];
		--end;
	}

	psl->array[pos - 1] = x;	//��x���뵽��pos��λ��
	psl->size++;	//��Ч����+1

}


//2.11 ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList * psl, size_t pos)
{
	//�ж�ָ��Ϸ���
	assert(psl);

	size_t start = pos-1;	//ָ��Ҫɾ����λ��
	while (start < psl->size-1)
	{
		psl->array[start] = psl->array[start + 1];
		++start;
	}

	psl->size--;	//��Ч����-1
}

//2.12 ˳�������
void SeqListDestory(SeqList * psl)
{
	//�ж�ָ��Ϸ���
	assert(psl);

	//����˳���
	free(psl->array);
	psl->array = NULL;
	psl->size = 0;
	psl->capacity = 0;

}