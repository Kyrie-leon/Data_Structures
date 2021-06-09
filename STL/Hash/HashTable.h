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

enum State {
	EMPTY,
	EXIST,
	DELETE
};

template <class T>
struct HashNode<T>
{
	State _state;	//״̬
	T	  _t;		//�洢ֵ
};

template<class K, class T�� class HashFunc = Hash<K>>
class HashTable {
public:
	bool Insert(const T &t)
	{
		//1.�ж��Ƿ���Ҫ���ݣ�ͨ�����������ж�0.7
		if (_tables.size() == 0 || _size * 10 / _tables.size() == 7)	//0.7תΪ����ֻ��0������÷���*10
		{
			size_t new_size = GetNextPrime(_tables.size());		//��ȡ���ݴ�С
			//1.�ؽ�һ���¹�ϣ��
			HashTable<K, T, HashFunc> new_hf;
			//2.�����µĹ�ϣ��
			new_hf._table.resize(new_size);
			//3.�����ɱ������±�ͨ��EXIST��־���ж�
			for (auto &e : _tables)
			{
				if(e._state == EXIST)
					new_hf.Insert(e._t);	//���ó�ͻʱ̽����߼�
			}
			//4.�����¾ɵ�ַ�ռ䣬�������
			new_hf.swap(_tables);

		}
		//2.����Ԫ��

	}
private:
	vector<HashNode<T>> _tables;	//��ϣ��
	size_t _size = 0;	//��Ч���ݸ���

};