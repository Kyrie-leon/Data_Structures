#include "mystring.h"

////////////////////////////////////////////////
//构造函数
mystring::string::string(const char * str)
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}
//拷贝构造
mystring::string::string(const string &s)
	:_size(0)
	, _capacity(0)
	, _str(nullptr)
{
	string tmp(s._str);
	swap(tmp);
}

void mystring::string::swap(string& s)
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

//=
mystring::string& mystring::string::operator=(string s)
{
	swap(s);
	return *this;
}
//析构函数
mystring::string::~string()
{
	if (_str)
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
}

////////////////////////////////////////////////////////////
//迭代器
mystring::string::iterator mystring::string::begin()
{
	return _str;
}

mystring::string::iterator mystring::string::end()
{
	return _str + _size;
}

mystring::string::const_iterator mystring::string::begin() const
{
	return _str;
}

mystring::string::const_iterator mystring::string::end() const
{
	return _str + _size;
}

///////////////////////////////////////////////////////
//修改
void mystring::string::push_back(char c)
{
	//容量满
	if (_size == _capacity)
		reserve(2 * _capacity);
	_str[_size++] = c;
	_str[_size] = '\0';
}

mystring::string& mystring::string::operator+=(char c)
{
	push_back(c);
	return *this;
}

void mystring::string::append(const char* str)
{
	//先判断追加后容量够不够
	size_t len = strlen(str);
	if (_capacity + len > _capacity)
	{
		reserve(2 * _capacity);
	}

	strcpy(_str + _size, str);
	_size += len;
}

mystring::string& mystring::string::operator+=(const char* str)
{
	append(str);

	return *this;
}

void mystring::string::clear()
{
	resize(0);
}

////////////////////////////////////////////////
// 容量操作
size_t mystring::string::size()const
{
	return _size;
}
size_t mystring::string::capacity()const
{
	return _capacity;
}

bool mystring::string::empty()const
{
	if (_size == 0)
		return true;
	return false;
}

void mystring::string::resize(size_t n, char c)
{
	//小于已有有效数字只用加个\0
	if (n < _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else 
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		for (size_t i = _size; i < n; ++i)
		{
			_str[i] = c;
		}
		_str[n] = '\0';
		_size = n;
	}
}

void mystring::string::reserve(size_t n)
{
	if (n > _capacity)
	{
		char* tmp = new char[n + 1];
		strcpy(tmp,_str);
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}

/////////////////////////////////////////////////////////////
// 元素访问操作
char& mystring::string::operator[](size_t index)
{
	assert(index < _size);
	return _str[index];
}
const char& mystring::string::operator[](size_t index)const
{
	assert(index < _size);
	return _str[index];
}

/////////////////////////////////////////////////////////////
//关系运算符
bool mystring::string::operator<(const string& s)
{
	size_t i1 = 0, i2 = 0;
	while (i1 < _size && i2 < s.size())
	{
		if (_str[i1] < s._str[i2])
		{
			return true;
		}
		else if (_str[i1] > s._str[i2])
		{
			return false;
		}
		else
		{
			++i1;
			++i2;
		}
	}
	if (i1 < _size)
	{
		return true;
	}
	else if (i2 < s.size())
	{
		return false;
	}
	else
	{
		return false;
	}
}

bool mystring::string::operator==(const string& s)
{
	size_t i1 = 0, i2 = 0;
	while (i1 < _size && i2 < s.size())
	{
		if (_str[i1] < s._str[i2])
		{
			return false;
		}
		else if (_str[i1] > s._str[i2])
		{
			return false;
		}
		else
		{
			++i1;
			++i2;
		}
	}
	if (i1 < _size)
	{
		return false;
	}
	else if (i2 < s.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool mystring::string::operator<=(const string& s)
{
	if (*this < s || *this == s)
	{
		return true;
	}
	return false;
}

bool mystring::string::operator>(const string& s)
{
	if (!(*this <= s))
	{
		return true;
	}

	return false;
}

bool mystring::string::operator>=(const string& s)
{
	if (!(*this < s))
	{
		return true;
	}
	return false;
}

bool mystring::string::operator!=(const string& s)
{
	if (!(*this == s))
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////////////
//字符串操作接口
const char* mystring::string::c_str() const
{
	return _str;
}
// 返回c在string中第一次出现的位置
size_t mystring::string::find(char c, size_t pos) const
{
	for (size_t i = pos; i < _size; ++i)
	{
		if (_str[i] == c)
			return i;
	}

	return npos;
}

// 返回子串s在string中第一次出现的位置
size_t mystring::string::find(const char* s, size_t pos) const
{
	const char* ret = strstr(_str + pos, s);
	if (ret == nullptr)
	{
		return npos;
	}
	else
	{
		return ret - _str;
	}
}

// 在pos位置上插入字符c/字符串str，并返回该字符的位置
mystring::string& mystring::string::insert(size_t pos, char c)
{
	assert(pos<=_size);
	if (_size == _capacity)
	{
		reserve(2 * _capacity);
	}
	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		--end;
	}

	_str[pos] = c;
	_size++;
}

mystring::string& mystring::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);

	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}

	size_t end = _size + len;
	while (end >= pos + len)
	{
		_str[end] = _str[end - len];
		--end;
	}

	strncpy(_str + pos, str, len);
	_size += len;
}
// 删除pos位置上的元素，并返回该元素的下一个位置
mystring::string& mystring::string::erase(size_t pos, size_t len)
{
	assert(pos < _size);

	if (len == npos || pos + len >= _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
	}
}


//////////////////////////////////////////////////////////////////////////
//非成员函数重载
std::ostream& mystring::operator<<(std::ostream& out, const string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		out << s[i];
	}

	return out;
}

std::istream& mystring::operator >> (std::istream& in, string& s)
{
	s.resize(0);
	char ch;
	while (1)
	{
		//in>>ch;
		in.get(ch);
		if (ch == ' ' || ch == '\n')
		{
			break;
		}
		else
		{
			s += ch;
		}
	}

	return in;
}


