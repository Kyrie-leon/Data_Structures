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


//闭散列
namespace Close {
	enum State {
		EMPTY,
		EXIST,
		DELETE
	};

	template <class T>
	struct HashNode
	{
		State _state;	//状态
		T	  _t;		//存储值
	};

	template<class K, class T, class HashFunc = Hash<K>>

	class HashTable 
	{
	public:
		//1.插入元素
		bool Insert(const T &t)
		{
			//1.判断是否需要增容，通过负载因子判断0.7
			if (_tables.size() == 0 || _size * 10 / _tables.size() == 7)	//0.7转为整形只有0，因此让分子*10
			{
				size_t new_size = GetNextPrime(_tables.size());		//获取增容大小
				//1.重建一个新哈希表
				HashTable<K, T, HashFunc> new_hf;
				//2.扩容新的哈希表
				new_hf._tables.resize(new_size);
				//3.遍历旧表，插入新表，通过EXIST标志来判断
				for (auto &e : _tables)
				{
					if (e._state == EXIST)
						new_hf.Insert(e._t);	//复用冲突时探测的逻辑
				}
				//4.交换新旧地址空间，完成扩容
				_tables.swap(new_hf._tables);

			}
			//2.判断是否存在，如果存在则返回false
			HashNode<T> *ret = Find(t);
			if (ret)
				return false;
			//3.插入元素
			HashFunc hf;
			//a.哈希函数转换获取初始位置
			size_t start = hf(t) % _tables.size();
			size_t index = start;
			size_t  i = 1;
			//b.通过状态解决哈希冲突线性探测
			while (_tables[index]._state == EXIST)
			{
				index = start + i;
				//细节：index如果一直加下去会出现越界，因此构造成环形队列
				index %= _tables.size();
				i++;
			}
			//c.将元素插入更新状态
			_tables[index]._t = t;
			_tables[index]._state = EXIST;
			//d.有效元素+1
			++_size;

			return true;
		}

		//2.查找元素
		HashNode<T>* Find(const K &key)
		{
			//1.哈希函数转换
			HashFunc hf;
			size_t start = hf(key) % _tables.size();
			size_t index = start;
			size_t i = 1;
			//2.线性探测，找空位置
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._t == key
					&& _tables[index]._state == EXIST)
				{
					return &_tables[index];
				}

				index = start + i;
				index %= _tables.size();
				++i;
			}

			return nullptr;
		}

		//3.删除
		bool Erase(const K &k)
		{
			//1.复用find找到这个元素
			HashNode<T> *ret = Find(k);

			//2.状态置DELETE
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				//伪删除
				ret->_state = DELETE;
				return true;
			}


		}




	private:
		vector<HashNode<T>> _tables;	//哈希表
		size_t _size = 0;	//有效数据个数
	};

	void TestHashTable()
	{
		HashTable<int,int> ht;
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(35);
		ht.Insert(45);
		ht.Insert(55);
		ht.Insert(65);
		ht.Insert(75);
		ht.Insert(85);
		ht.Insert(95);
		ht.Insert(108);

		HashTable<string, string> st;
		st.Insert("sort");
		st.Insert("insert");
	}
}


//开散列哈希桶
namespace Open {
	template<class T>
	struct HashLinkNode
	{
		T _t;	//元素
		HashLinkNode<T> *_next;

		//构造函数
		HashLinkNode(const T &t)
			:_t(t)
			,_next(nullptr)
		{}
	};

	//前置声明
	template<class K, class T, class KeyOfT, class hash>
	class HashTable;

	template<class K, class T, class KeyOfT, class hash>
	class HashTable {

	};


}