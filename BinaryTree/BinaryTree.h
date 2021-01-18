#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType _data;	// ��ǰ�ڵ�ֵ��
	struct BinaryTreeNode* _left;	// ָ��ǰ�ڵ�����
	struct BinaryTreeNode* _right;	// ָ��ǰ�ڵ��Һ���
	BTDataType _data;
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
void PrevOrder(BTNode* root);

// �������������
void InOrder(BTNode* root);

// �������������
void PostOrder(BTNode* root);

// �������
void LevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);