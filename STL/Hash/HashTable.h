#pragma once

template<class K>
struct Hash
{
	size_t operator()(const K &key)
	{
		return key;
	}
};

//模板特化，用于处理string类型
template<>
struct Hash<string>
{
	//字符串中的字符累加和
	size_t operator()(const string &s)
	{
		int hash = 0;
		for (auto& ch : s)
		{
			hash += ch;
		}
		return hash;
	}
};

//静态全局变量
static size_t GetNextPrime(size_t prime)
{
	//全部的素数数组一共28个
	static const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	//获取下一次的素数,只要比传进来的素数大就可以返回
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}

	return primeList[i];
}

enum State {
	EMPTY,
	EXIST,
	DELETE
};

template <class T>
struct HashNode<T>
{
	State _state;	//状态
	T	  _t;		//存储值
};

template<class K, class T， class HashFunc = Hash<K>>
class HashTable {
public:
	bool Insert(const T &t)
	{
		//1.判断是否需要增容，通过负载因子判断0.7
		if (_tables.size() == 0 || _size * 10 / _tables.size() == 7)	//0.7转为整形只有0，因此让分子*10
		{
			size_t new_size = GetNextPrime(_tables.size());		//获取增容大小
			//1.重建一个新哈希表
			HashTable<K, T, HashFunc> new_hf;
			//2.扩容新的哈希表
			new_hf._table.resize(new_size);
			//3.遍历旧表，插入新表，通过EXIST标志来判断
			for (auto &e : _tables)
			{
				if(e._state == EXIST)
					new_hf.Insert(e._t);	//复用冲突时探测的逻辑
			}
			//4.交换新旧地址空间，完成扩容
			new_hf.swap(_tables);

		}
		//2.插入元素

	}
private:
	vector<HashNode<T>> _tables;	//哈希表
	size_t _size = 0;	//有效数据个数

};