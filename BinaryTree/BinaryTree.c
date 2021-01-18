#include"BinaryTree.h"

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
		printf("NULL");
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
		printf("NULL");
		return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}