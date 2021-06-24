#pragma once
#include<vector>

namespace leon
{
	template<size_t N>
	class bitset
	{
	public:
		//构造函数
		bitset()
		{
			//如果N恰好是8，只除以8会少一位，因此多开一个字节
			_bits.resize((N >> 3)+ 1, 0);	//N >> 3 == N / 8
		}

		//将x比特位置1
		void set(size_t x)
		{
			size_t index = x >> 3;	//求出x所在的下标index
			size_t num = x % 8;		//求出需要移num位
			_bits[index] |= (1 << num);	//将第num位置1
		}

		//将x比特位置0
		void reset(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			_bits[index] &= ~(1 << num);
		}

		//检查位图中x是否为1
		bool test(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			return _bits[index] & (1 << num);
		}

	private:
		//两种写法
		std::vector<char> _bits;	//一个字节8位
		//std::vector<int> _bits;		//4个字节32位
	};

	void testbitset()
	{
		bitset<100> bs;
		bs.set(12);
		bs.set(49);
		bs.set(60);

		std::cout << bs.test(12) << std::endl;
		std::cout << bs.test(49) << std::endl;
		std::cout << bs.test(60) << std::endl;
		std::cout << bs.test(90) << std::endl << std::endl;
		bs.reset(60);
		bs.set(80);
		std::cout << bs.test(12) << std::endl;
		std::cout << bs.test(49) << std::endl;
		std::cout << bs.test(60) << std::endl;
		std::cout << bs.test(80) << std::endl;
		std::cout << bs.test(90) << std::endl << std::endl;


	}

}