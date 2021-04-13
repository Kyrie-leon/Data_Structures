
#if 0
//string浅拷贝
namespace leon
{
	class string
	{
	public:
		//string构造函数
		string(const char* str = "")
		{
			assert(str);	//如果str为nullptr直接报错
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

	private:
		char *_str;

	};
}

void Teststring1()
{
	leon::string s1("hello");
	leon::string s2(s1);
}
#endif

#if 0
//传统版的string类
namespace leon
{
	class string
	{
	public:
		//string构造函数
		string(const char* str = "")
		{
			assert(str);	//如果str为nullptr直接报错
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string &s)
		{
			//自己不给自己赋值
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

	private:
		char *_str;

	};
}
#endif

#if 0
//现代写法
//思路：编译器开空间，
namespace leon
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char(strlen(str)+1))
		{
			strcpy(_str,str);
		}

		//s2(s1)
		string(const string &s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);	//交换空间地址
		}

		/*
		//s1=s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);	//不但交换空间，出了作用域还会调用析构函数释放空间
			}

			return *this;
		}
		*/

		//s1 = s3
		string& operator=(string s) //string s = string tmp(s)拷贝构造
		{
			swap(_str, s._str);
			return *this;
		}

		~string()
		{
			delete[] _str;
		}
	private:
		char *_str;
	};
}
#endif

#if 0
namespace leon
{
	class string
	{
	public:
		//构造函数
		string(const char *str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);

		}
		//拷贝构造函数s2(s1)
		string(const string &s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)

		{
			string tmp(s._str);
			Swap(tmp);
		}

		string& operator=(string s)
		{
			Swap(s);
			return *this;
		}

		//s1.Swap(s2)
		void Swap(string &s)
		{
			swap(_str, s._str);
			swap(_capacity, s._capacity);
			swap(_size, s._size);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//迭代器
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//修改
		//void push_back(char c)
		//{
		//	//判断容量大小
		//	if (_size == _capacity)
		//		reserve(_capacity * 2);
		//	_str[_size] = ch;

		//}

		void insert(size_t pos, char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * capacity);
			}

			size_t end = _size+1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

		}
		
		size_t find(size_t pos, char ch)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
	private:
		char *_str;
		size_t _capacity;
		size_t _size;
	public:
		static const size_t npos;
	};

	const size_t npos = -1;
}
#endif

#include "mystring.h"

int main()
{
	//构造函数
	mystring::string s("hello world!");
	mystring::string s2(s);

	// capacity
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << std::endl;
	std::cout << s.empty() << std::endl;
	s.resize(17);
	s.resize(12, 'x');

	s.reserve(100);
	std::cout << s.capacity()<<std::endl;

	////modify
	s2.push_back('1');
	s2.push_back('2');
	s2.push_back('3');
	s2.push_back('4');
	s2 += '5';
	s2 += "678";
	s2.append("xxxxx");
	s2.clear();

	//access
	mystring::string s3("hello world!");
	mystring::string s4("hello world!");

	std::cout << s3[3] << std::endl;

	/////////////////////////////////////////////////////////////
	//relational operators
	bool t;
	t = s3 < s4;
	t = s3 <= s4;
	t = s3 == s4;
	t = s3 > s4;
	t = s3 >= s4;

	size_t i = s3.find('w');
	std::cout << s3;

	return 0;
}