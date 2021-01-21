#pragma once
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType _data;	// ��ǰ�ڵ�ֵ��
	struct BinaryTreeNode* _left;	// ָ��ǰ�ڵ�����
	struct BinaryTreeNode* _right;	// ָ��ǰ�ڵ��Һ���
}BTNode;


//�����������ڵ�
BTNode* CreateNode(int x);

//����������ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* CreateTree(BTDataType* a, int* pi);

//����������
void BinaryTreeDestory(BTDataType** root);

//������������
int TreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root);

// ��������k��ڵ����
int TreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);

// ������ǰ�����
void PrevOrder(BTNode* root);

// �������������
void InOrder(BTNode* root);

// �������������
void PostOrder(BTNode* root);

// �������
void LevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int TreeComplete(BTNode* root);