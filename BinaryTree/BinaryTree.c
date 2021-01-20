#include"BinaryTree.h"
#include"Queue.h"


//�����������Ľڵ�
BTNode* CreateNode(int x)
{
	BTNode* node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

// ������ǰ�����
void PrevOrder(BTNode* root)
{
	if (root == NULL)	//��ǰ�ڵ�Ϊ��ʱ��ӡNULL������
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);		//��ӡ��ǰ�ڵ�
	PrevOrder(root->_left);	//������ǰ�ڵ�������
	PrevOrder(root->_right);	//������ǰ�ڵ�������
}

// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);	//����������
	printf("%c ", root->_data);	//��ӡ��ǰ�ڵ�
	InOrder(root->_right);	//����������
}

// �������������
void PostOrder(BTNode* root)
{
	if(root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
void LevelOrder(BTNode* root)
{
	Queue q;	//��������
	QueueInit(&q);	//��ʼ������
	if (root == NULL)	//������Ϊ��ֱ�ӷ���
		return;
	QueuePush(&q, root);	//���ڵ����
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);	//��ȡ��ͷ���
		QueuePop(&q);	//��ͷ����
		printf("%c ", front->_data);
		//�ڵ�front����ڵ���ҽڵ��������
		if (front->_left)	
		{
			QueuePush(&q, front->_left);	//��ڵ����
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);	//�ҽڵ����
		}

	}
	printf("\n");
	QueueDestroy(&q);	//���ٶ���
}

// �ж϶������Ƿ�����ȫ������
//�Ƿ���1�����Ƿ���0
int TreeComplete(BTNode* root)
{
	Queue q;
	if (root == NULL)
		return 1;
	QueueInit(&q);
	QueuePush(&q, root);
	//����������нڵ�
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//������ֻҪ��NULLԪ�ؾ��˳�ѭ��
		if (front == NULL)
			break;
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	//������������Ԫ�س��ӣ���ʱ��ȫ���������ж�ΪNULL������ȫ�����������д���������ֵԪ��
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//������ֻҪ�в�ΪNULL��Ԫ��˵��������ȫ������
		if (front)
		{
			QueueDestroy(&q);
			return 0;
		}
	}

	QueueDestroy(&q);
	return 1;

}

//������������
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}

// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//ֻ��Ҷ�ӽڵ����������Ϊ��
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

// ��������k��ڵ����
//��k��Ҷ�ӽڵ�ĸ������ǵ�ǰ�����������ĵ�k-1��ڵ��������k==1ʱ�Ͳ��ٷֽ�
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->_left,k-1)+ TreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//��ǰ�ڵ�ֵ����x���ص�ǰ�ڵ�ֵ
	if (root->_data == x)
		return root;
	
	//δ�ҵ��ͱ������������ҵ����򷵻�
	BTNode* findNode = TreeFind(root->_left, x);
	if (findNode)
		return findNode;
	//������δ�ҵ�������������
	findNode = TreeFind(root->_right, x);
	if (findNode)
		return findNode;

	return NULL;
}
