#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;	//��ͷ��β�ÿռ���

}
// ��β����� 
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QNode * newNode = (QNode *)malloc(sizeof(QNode));	//���ڴ�����һ�����
	//�ж��Ƿ�����ɹ�
	if (NULL == newNode)
	{
		printf("����ʧ��!\n");
		exit(-1);
	}
	//���½ڵ��뵽��β
	newNode->_data = data;	//����data��ֵ���½ڵ�	
	newNode->_next = NULL;	//�½ڵ����Ϊ��β�ڵ㣬��˶��½ڵ�_next�ÿ�
	
	if (pq->_front)
	{
		pq->_rear->_next = newNode;		//���в�Ϊ�գ���β����������½��
		pq->_rear = newNode;	//�ٽ���βָ���½ڵ�	
	}
	else
	{
		pq->_front = pq->_rear = newNode;	//�������Ϊ�գ����ͷ��β��ָ���½ڵ�
	}
}

// ��ͷ������ 
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_front);	//�������ж϶����Ƿ�Ϊ��
	QNode* next = pq->_front->_next;	//next�����¶�ͷ���
	free(pq->_front);
	pq->_front = next;
	//�����к���Ҫ�ж϶����Ƿ�Ϊ��
	if (NULL == pq->_front)
	{
		pq->_rear = NULL;	//���Ϊ�գ����βҲΪ��
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_rear);
	return pq->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->_front;
	//����һ������
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 1 : 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//��ͷ�ڵ㿪ʼ����ÿһ���ڵ㲢free
	QNode* cur = pq->_front;
	while (cur)
	{
		QNode* next = cur->_next;	//curָ����һ���ڵ�
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}