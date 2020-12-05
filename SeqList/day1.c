#include <stdio.h>
#include <assert.h>
#include <windows.h>

//5.模拟实现strstr
const char *my_strstr(const char* str, const char* sub_str)
{
	//判断指针合法性
	assert(str != NULL);
	assert(sub_str != NULL);

	//双层循环实现字符串子串查找
	//外层循环控制str起始位置，一直向后移动直到\0
	while (*str)
	{
		//定义两个指针变量方便返回字符串起始地址
		const char *p = str;
		const char *q = sub_str;
		//内层循环用于判断str字符串是否包含sub_str子串
		while ((*p == *q)&&*p&&*q)
		{

			p++;
			q++;
		}
		//如果sub_str扫描到\0说明在str中找到子串，返回str中的子串首字符的起始地址
		if (*q == '\0')
		{
			return str;
		}
		str++;
	}


	return NULL;

}

//1.模拟实现memcpy
void * my_memcpy(void * dst, const void * src, size_t num)
{
	//判断指针合法性
	assert(dst != NULL);
	assert(src != NULL);

	//将void *强制类型转为char *，方便按字节拷贝
	char *_dst = (char *)dst;
	const char * _src = (const char *)src;

	//拷贝num个字节
	while (num)
	{
		*_dst = *_src;
		_dst++;
		_src++;
		num--;
	}

	return dst;


}

//2.模拟实现memmove
void *my_memmove(void *dst, const void *src, size_t num)
{
	//判断指针合法性
	assert(dst != NULL);
	assert(src != NULL);

	//将void *强制类型转为char *，方便按字节拷贝
	char *_dst = (char *)dst;
	const char * _src = (const char *)src;

	//情况3从右向左拷贝
	if (_dst > _src && _dst < _src + num)
	{
		//首先让dst与src指向最右边
		_dst = _dst + num - 1;
		_src = _src + num - 1;

		//拷贝num个字节
		while (num)
		{
			*_dst = *_src;
			_dst--;
			_src--;
			num--;
		}
	}
	//其他情况全部从左向右拷贝
	else
	{
		//拷贝num个字节
		while (num)
		{
			*_dst = *_src;
			_dst++;
			_src++;
			num--;
		}
	}

	return dst;
}

int main()
{
	//1.
	//内存不重叠
	//char dst = "12cde";
	//char *src = "ab123";
	//my_memcpy(&dst, &src,strlen(src));
	////memcpy(&dst, &src, strlen(src));
	//printf("%s\n", src);
	//内存重叠
	//char buf[16] = "abcdef";
	//my_memcpy(buf + 1, buf, strlen(buf)+1);
	//printf("%s\n", buf);

	////2.
	////内存重叠
	//char buf[16] = "abcdef";
	//my_memmove(buf + 1, buf, strlen(buf) + 1);
	//printf("%s\n", buf);

	//4.库函数验证
	char buf1[16] = "abcdef";
	memcpy(buf1 + 1, buf1, strlen(buf1)+1);
	printf("库函数memcpy：%s\n", buf1);

	char buf2[16] = "abcdef";
	memmove(buf2 + 1, buf2, strlen(buf2) + 1);
	printf("库函数memove：%s\n", buf2);


	////5.
	//char *str = "abcd adef abcde123 fg";
	//char *sub_str = "de123";
	//printf("%s\n", my_strstr(str, sub_str));

	system("pause");
	return 0;
}