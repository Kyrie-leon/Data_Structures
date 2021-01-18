#include"BinaryTree.h"

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
		printf("NULL");
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
		printf("NULL");
		return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}