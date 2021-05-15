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
//	//Ò¶×Ó
//	t.Erase(1);
//	t.InOrder();
//	//×ó×ÓÊ÷
//	t.Erase(4);
//	t.InOrder();
//	//ÓÒ×ÓÊ÷
//	t.Erase(7);
//	//¸ù
//	t.Erase(5);
//	t.InOrder();
//	t.InOrder();
//	
//	const BSTNode<int>* ret = t.Find(6);
//	if (ret)
//	{
//		cout << "ÕÒµ½ÁË" << endl;
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
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("insert", "²åÈë");
	dict.Insert("left", "×ó±ß");

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
	cout << "µ¥´Ê²»´æÔÚ" << endl;
	}
	}*/

	string strArr[] = { "Æ»¹û", "Æ»¹û","Ïã½¶","Ïã½¶","Ïã½¶","Ïã½¶", "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Æ»¹û" };
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