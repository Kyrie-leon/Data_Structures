#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;	//队头队尾置空即可

}
// 队尾入队列 
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QNode * newNode = (QNode *)malloc(sizeof(QNode));	//向内存申请一个结点
	//判断是否申请成功
	if (NULL == newNode)
	{
		printf("申请失败!\n");
		exit(-1);
	}
	//将新节点入到队尾
	newNode->_data = data;	//数据data赋值给新节点	
	newNode->_next = NULL;	//新节点会作为队尾节点，因此对新节点_next置空
	
	if (pq->_front)
	{
		pq->_rear->_next = newNode;		//队列不为空，队尾结点先链接新结点
		pq->_rear = newNode;	//再将队尾指向新节点	
	}
	else
	{
		pq->_front = pq->_rear = newNode;	//如果队列为空，则队头队尾都指向新节点
	}
}

// 队头出队列 
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_front);	//出队列判断队列是否为空
	QNode* next = pq->_front->_next;	//next保存新队头结点
	free(pq->_front);
	pq->_front = next;
	//出队列后需要判断队列是否为空
	if (NULL == pq->_front)
	{
		pq->_rear = NULL;	//如果为空，则队尾也为空
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_rear);
	return pq->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->_front;
	//遍历一遍链表
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//从头节点开始遍历每一个节点并free
	QNode* cur = pq->_front;
	while (cur)
	{
		QNode* next = cur->_next;	//cur指向下一个节点
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}