#pragma once
template<class K>
struct Hash
{
	size_t operator()(const K &key)
	{
		return key;
	}
};

//ģ���ػ������ڴ���string����
template<>
struct Hash<string>
{
	//�ַ����е��ַ��ۼӺ�
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

//��̬ȫ�ֱ���
static size_t GetNextPrime(size_t prime)
{
	//ȫ������������һ��28��
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

	//��ȡ��һ�ε�����,ֻҪ�ȴ�������������Ϳ��Է���
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}

	return primeList[i];
}


//��ɢ��
namespace Close {
	enum State {
		EMPTY,
		EXIST,
		DELETE
	};

	template <class T>
	struct HashNode
	{
		State _state;	//״̬
		T	  _t;		//�洢ֵ
	};

	template<class K, class T, class HashFunc = Hash<K>>

	class HashTable 
	{
	public:
		//1.����Ԫ��
		bool Insert(const T &t)
		{
			//1.�ж��Ƿ���Ҫ���ݣ�ͨ�����������ж�0.7
			if (_tables.size() == 0 || _size * 10 / _tables.size() == 7)	//0.7תΪ����ֻ��0������÷���*10
			{
				size_t new_size = GetNextPrime(_tables.size());		//��ȡ���ݴ�С
				//1.�ؽ�һ���¹�ϣ��
				HashTable<K, T, HashFunc> new_hf;
				//2.�����µĹ�ϣ��
				new_hf._tables.resize(new_size);
				//3.�����ɱ������±�ͨ��EXIST��־���ж�
				for (auto &e : _tables)
				{
					if (e._state == EXIST)
						new_hf.Insert(e._t);	//���ó�ͻʱ̽����߼�
				}
				//4.�����¾ɵ�ַ�ռ䣬�������
				_tables.swap(new_hf._tables);

			}
			//2.�ж��Ƿ���ڣ���������򷵻�false
			HashNode<T> *ret = Find(t);
			if (ret)
				return false;
			//3.����Ԫ��
			HashFunc hf;
			//a.��ϣ����ת����ȡ��ʼλ��
			size_t start = hf(t) % _tables.size();
			size_t index = start;
			size_t  i = 1;
			//b.ͨ��״̬�����ϣ��ͻ����̽��
			while (_tables[index]._state == EXIST)
			{
				index = start + i;
				//ϸ�ڣ�index���һֱ����ȥ�����Խ�磬��˹���ɻ��ζ���
				index %= _tables.size();
				i++;
			}
			//c.��Ԫ�ز������״̬
			_tables[index]._t = t;
			_tables[index]._state = EXIST;
			//d.��ЧԪ��+1
			++_size;

			return true;
		}

		//2.����Ԫ��
		HashNode<T>* Find(const K &key)
		{
			//1.��ϣ����ת��
			HashFunc hf;
			size_t start = hf(key) % _tables.size();
			size_t index = start;
			size_t i = 1;
			//2.����̽�⣬�ҿ�λ��
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

		//3.ɾ��
		bool Erase(const K &k)
		{
			//1.����find�ҵ����Ԫ��
			HashNode<T> *ret = Find(k);

			//2.״̬��DELETE
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				//αɾ��
				ret->_state = DELETE;
				return true;
			}


		}




	private:
		vector<HashNode<T>> _tables;	//��ϣ��
		size_t _size = 0;	//��Ч���ݸ���
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


//��ɢ�й�ϣͰ
namespace Open {
	template<class T>
	struct HashLinkNode
	{
		T _t;	//Ԫ��
		HashLinkNode<T> *_next;

		//���캯��
		HashLinkNode(const T &t)
			:_t(t)
			,_next(nullptr)
		{}
	};

	//ǰ������
	template<class K, class T, class KeyOfT, class hash>
	class HashTable;

	template<class K, class T, class KeyOfT, class hash>
	class HashTable {

	};


}