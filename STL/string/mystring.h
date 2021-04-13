#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <assert.h>
#include <utility>


namespace mystring
{
	
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		const static size_t npos = -1;
		friend std::ostream& mystring::string::operator<<(std::ostream& out, const string& s);
		friend std::istream& mystring::string::operator >> (std::istream& in, string& s);
	public:
		//构造函数
		string(const char * str = "");
		//拷贝构造函数
		string(const string &s);
		//析构函数
		~string();

		string& operator=(string s);
		
		//////////////////////////////////////////////////////////////
		// 迭代器和常量迭代器
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		/////////////////////////////////////////////////////////////
		// 容量接口
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		void clear();
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);

		/////////////////////////////////////////////////////////////
		// 元素访问接口
		char& operator[](size_t index);
		const char& operator[](size_t index)const;

		/////////////////////////////////////////////////////////////
		// 修改接口
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void swap(string& s);


		/////////////////////////////////////////////////////////////
		//关系运算符操做接口
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);


		/////////////////////////////////////////////////////////////
		//字符串操作接口
		const char* c_str() const;
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len);

	private:
		char *_str;
		size_t _capacity;
		size_t _size;
	};
}