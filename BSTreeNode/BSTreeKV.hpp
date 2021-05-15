#pragma once

template<class K, class V>
struct BSTNode {
	const K _key;	//不能改变
	V _value;
	struct BSTNode<K, V> * _pleft;	//左孩子
	struct BSTNode<K, V> * _pright; //右孩子

	BSTNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		, _pleft(nullptr)
		, _pright(nullptr)
	{}
};

template<class K, class V>
class BSTree {
	typedef struct BSTNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	//二叉树的查找
	Node* Find(const K& key)
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
		return nullptr; //空树直接返回
	}
	//二叉搜索树插入
	bool Insert(const K& key, const V& value)
	{
		//1.空树直接插入
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}
		//2.不为空
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

		Node* newNode = new Node(key,value);
		if (parent->_key > key)
			parent->_pleft = newNode;
		else
			parent->_pright = newNode;

		return true;
	}
	//二叉搜索树的删除
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
				//三种情况：1.左为空 2.右为空 3.都不为空
				if (cur->_pleft == nullptr)
				{
					//1.左为根节点,直接让右子树变为根节点
					if (cur == _root)
					{
						_root = cur->_pright;
					}
					else
					{
						//两种情况：1.parent的左子树 2.parent的右子树
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
					//同上的情况
					if (cur == _root)
					{
						_root = cur->_pleft;
					}
					else
					{
						//两种情况：1.parent的右子树 2.parent的左子树
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
					//替代法，右树中找最小,需要注意一个情况右树就是最小值
					Node* smParent = cur;
					Node* subMin = cur->_pright;
					//找右树中的最小值，一定是在右数的最左边
					while (subMin->_pleft)
					{
						smParent = subMin;
						subMin = subMin->_pleft;
					}
					//把要删除的节点值替换成右数最小值
					cur->_key = subMin->_key;

					if (smParent->_pleft == subMin)
					{
						smParent->_pleft = subMin->_pright;
					}
					else//右子树是最小值
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

	//先序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_pleft);
		cout << root->_key << ":"<< root->_value<< endl;
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