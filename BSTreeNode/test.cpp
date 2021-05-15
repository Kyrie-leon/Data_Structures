//#include"BSTree.hpp"

//void TestBSTree()
//{
//	BSTree<int> t;
//	t.Insert(5);
//	t.Insert(2);
//	t.Insert(6);
//	t.Insert(7);
//	t.Insert(1);
//	t.Insert(4);
//	t.Insert(3);
//	t.Insert(9);
//	t.InOrder();
//	//Ҷ��
//	t.Erase(1);
//	t.InOrder();
//	//������
//	t.Erase(4);
//	t.InOrder();
//	//������
//	t.Erase(7);
//	//��
//	t.Erase(5);
//	t.InOrder();
//	t.InOrder();
//	
//	const BSTNode<int>* ret = t.Find(6);
//	if (ret)
//	{
//		cout << "�ҵ���" << endl;
//	}
//
//}

#include"BSTreeKV.hpp"
#include<string>
#include<iostream>
using namespace std;
void TestBSTreeKV()
{
	BSTree<string, string> dict;
	dict.Insert("string", "�ַ���");
	dict.Insert("sort", "����");
	dict.Insert("insert", "����");
	dict.Insert("left", "���");

	dict.InOrder();
	/*string str;
	while (cin>>str)
	{
	BSTreeNode<string, string>* ret = dict.Find(str);
	if (ret)
	{
	cout << ret->_value << endl;
	}
	else
	{
	cout << "���ʲ�����" << endl;
	}
	}*/

	string strArr[] = { "ƻ��", "ƻ��","�㽶","�㽶","�㽶","�㽶", "����", "����", "ƻ��", "ƻ��" };
	BSTree<string, int> countTree;
	for (auto& str : strArr)
	{
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}
int main()
{
	TestBSTreeKV();
	return 0;
}