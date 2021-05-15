#pragma once

template<class K>
struct BSTNode {
	K _key;
	struct BSTNode<K> * _pleft;	//����
	struct BSTNode<K> * _pright; //�Һ���

	BSTNode(const K& key)
		:_key(key)
		,_pleft(nullptr)
		,_pright(nullptr)
	{}
};

template<class K>
class BSTree {
	typedef struct BSTNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	//�������Ĳ���
	const Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_pleft;
			}
			else if (cur->_key < key)
			{
				cur = cur->_pright;
			}
			else
			{
				return cur;
			}
		}
		return nullptr; //����ֱ�ӷ���
	}
	//��������������
	bool Insert(const K& key)
	{
		//1.����ֱ�Ӳ���
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		//2.��Ϊ��
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_pleft;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else
			{
				return false;
			}
		}

		Node* newNode = new Node(key);
		if (parent->_key > key)
			parent->_pleft = newNode;
		else
			parent->_pright = newNode;

		return true;
	}
	//������������ɾ��
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_pleft;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else
			{
				//���������1.��Ϊ�� 2.��Ϊ�� 3.����Ϊ��
				if (cur->_pleft == nullptr)
				{
					//1.��Ϊ���ڵ�,ֱ������������Ϊ���ڵ�
					if (cur == _root)
					{
						_root = cur->_pright;
					}
					else
					{
						//���������1.parent�������� 2.parent��������
						if (cur == parent->_pleft)
						{
							parent->_pleft = cur->_pright;
						}
						else
						{
							parent->_pright = cur->_pright;
						}
					}
					delete cur;
				}
				else if (cur->_pright == nullptr)
				{
					//ͬ�ϵ����
					if (cur == _root)
					{
						_root = cur->_pleft;
					}
					else
					{
						//���������1.parent�������� 2.parent��������
						if (cur == parent->_pright)
						{
							parent->_pright = cur->_pleft;
						}
						else
						{
							parent->_pleft = cur->_pleft;
						}
					}
					delete cur;
				}
				else
				{
					//�����������������С,��Ҫע��һ���������������Сֵ
					Node* smParent = cur;
					Node* subMin = cur->_pright;
					//�������е���Сֵ��һ�����������������
					while (subMin->_pleft)
					{
						smParent = subMin;
						subMin = subMin->_pleft;
					}
					//��Ҫɾ���Ľڵ�ֵ�滻��������Сֵ
					cur->_key = subMin->_key;
					
					if (smParent->_pleft == subMin)
					{
						smParent->_pleft = subMin->_pright;
					}
					else//����������Сֵ
					{
						smParent->_pright = subMin->_pright;
					}
					delete subMin;
				}
				return true;
			}
			
		}
		return false;
	}

	//�������
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_pleft);
		cout << root->_key << " ";
		_InOrder(root->_pright);

	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root;
};