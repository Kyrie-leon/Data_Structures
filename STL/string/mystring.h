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
		//���캯��
		string(const char * str = "");
		//�������캯��
		string(const string &s);
		//��������
		~string();

		string& operator=(string s);
		
		//////////////////////////////////////////////////////////////
		// �������ͳ���������
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		/////////////////////////////////////////////////////////////
		// �����ӿ�
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		void clear();
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);

		/////////////////////////////////////////////////////////////
		// Ԫ�ط��ʽӿ�
		char& operator[](size_t index);
		const char& operator[](size_t index)const;

		/////////////////////////////////////////////////////////////
		// �޸Ľӿ�
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void swap(string& s);


		/////////////////////////////////////////////////////////////
		//��ϵ����������ӿ�
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);


		/////////////////////////////////////////////////////////////
		//�ַ��������ӿ�
		const char* c_str() const;
		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const;
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const;
		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len);

	private:
		char *_str;
		size_t _capacity;
		size_t _size;
	};
}