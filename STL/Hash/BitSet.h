#pragma once
#include<vector>

namespace leon
{
	template<size_t N>
	class bitset
	{
	public:
		//���캯��
		bitset()
		{
			//���Nǡ����8��ֻ����8����һλ����˶࿪һ���ֽ�
			_bits.resize((N >> 3)+ 1, 0);	//N >> 3 == N / 8
		}

		//��x����λ��1
		void set(size_t x)
		{
			size_t index = x >> 3;	//���x���ڵ��±�index
			size_t num = x % 8;		//�����Ҫ��numλ
			_bits[index] |= (1 << num);	//����numλ��1
		}

		//��x����λ��0
		void reset(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			_bits[index] &= ~(1 << num);
		}

		//���λͼ��x�Ƿ�Ϊ1
		bool test(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			return _bits[index] & (1 << num);
		}

	private:
		//����д��
		std::vector<char> _bits;	//һ���ֽ�8λ
		//std::vector<int> _bits;		//4���ֽ�32λ
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