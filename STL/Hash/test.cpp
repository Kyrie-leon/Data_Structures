#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#include"HashTable.hpp"
#include"unordered_map.h"
#include"unordered_set.h"

void Test_unordered_set()
{
	unordered_set<int> us;
	us.insert(1);
	us.insert(54);
	us.insert(58);
	us.insert(58);
	us.insert(59);
	us.insert(100);

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_unordered_map()
{
	unordered_map<string, string> dict;
	dict["sort"] = "ÅÅĞò";
	dict["hash"] = "¹şÏ£";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	//Close::TestHashTable();

	leon::test_unordered_map();
	test_unordered_map();
	leon::test_unordered_set();
	Test_unordered_set();
	return 0;
}