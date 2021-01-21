#pragma once
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType _data;	// 当前节点值域
	struct BinaryTreeNode* _left;	// 指向当前节点左孩子
	struct BinaryTreeNode* _right;	// 指向当前节点右孩子
}BTNode;


//构建二叉树节点
BTNode* CreateNode(int x);

//构建二叉树通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* CreateTree(BTDataType* a, int* pi);

//二叉树销毁
void BinaryTreeDestory(BTDataType** root);

//二叉树结点个数
int TreeSize(BTNode* root);

// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root);

// 二叉树第k层节点个数
int TreeLevelKSize(BTNode* root, int k);

// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);

// 二叉树前序遍历
void PrevOrder(BTNode* root);

// 二叉树中序遍历
void InOrder(BTNode* root);

// 二叉树后序遍历
void PostOrder(BTNode* root);

// 层序遍历
void LevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
int TreeComplete(BTNode* root);