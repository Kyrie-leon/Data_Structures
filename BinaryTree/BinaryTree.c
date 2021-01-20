#include"BinaryTree.h"
#include"Queue.h"


//创建二叉树的节点
BTNode* CreateNode(int x)
{
	BTNode* node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

// 二叉树前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)	//当前节点为空时打印NULL并返回
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);		//打印当前节点
	PrevOrder(root->_left);	//遍历当前节点左子树
	PrevOrder(root->_right);	//遍历当前节点右子树
}

// 二叉树中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);	//遍历左子树
	printf("%c ", root->_data);	//打印当前节点
	InOrder(root->_right);	//遍历右子树
}

// 二叉树后序遍历
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

// 层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;	//创建队列
	QueueInit(&q);	//初始化队列
	if (root == NULL)	//二叉树为空直接返回
		return;
	QueuePush(&q, root);	//根节点入队
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);	//获取队头结点
		QueuePop(&q);	//队头出队
		printf("%c ", front->_data);
		//节点front的左节点和右节点依次入队
		if (front->_left)	
		{
			QueuePush(&q, front->_left);	//左节点入队
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);	//右节点入队
		}

	}
	printf("\n");
	QueueDestroy(&q);	//销毁队列
}

// 判断二叉树是否是完全二叉树
//是返回1，不是返回0
int TreeComplete(BTNode* root)
{
	Queue q;
	if (root == NULL)
		return 1;
	QueueInit(&q);
	QueuePush(&q, root);
	//层序遍历所有节点
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//队列中只要又NULL元素就退出循环
		if (front == NULL)
			break;
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	//将队列中所有元素出队，此时完全二叉树队列都为NULL，非完全二叉树队列中存在其他数值元素
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//队列中只要有不为NULL的元素说明不是完全二叉树
		if (front)
		{
			QueueDestroy(&q);
			return 0;
		}
	}

	QueueDestroy(&q);
	return 1;

}

//二叉树结点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}

// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//只有叶子节点的左右子树为空
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
//第k层叶子节点的个数就是当前层左右子树的第k-1层节点个数，当k==1时就不再分解
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->_left,k-1)+ TreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//当前节点值等于x返回当前节点值
	if (root->_data == x)
		return root;
	
	//未找到就遍历左子树，找到了则返回
	BTNode* findNode = TreeFind(root->_left, x);
	if (findNode)
		return findNode;
	//左子树未找到，遍历右子树
	findNode = TreeFind(root->_right, x);
	if (findNode)
		return findNode;

	return NULL;
}
