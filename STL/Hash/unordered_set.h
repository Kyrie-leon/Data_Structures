#pragma once
#include "HashTable.hpp"

namespace leon
{
	template<class K, class hash = Hash<K>>
	class unordered_set
	{
		struct SetKOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename Open::HashTable<K, K, SetKOfT, hash>::Iterator iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		Open::HashTable<K, K, SetKOfT, hash> _t;
	};

	void test_unordered_set()
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
}
