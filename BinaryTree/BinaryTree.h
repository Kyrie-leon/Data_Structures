#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

//����������
void BinaryTreeDestory(BTDataType** root);

//������������
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);