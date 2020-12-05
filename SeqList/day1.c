#include <stdio.h>
#include <assert.h>
#include <windows.h>

//5.ģ��ʵ��strstr
const char *my_strstr(const char* str, const char* sub_str)
{
	//�ж�ָ��Ϸ���
	assert(str != NULL);
	assert(sub_str != NULL);

	//˫��ѭ��ʵ���ַ����Ӵ�����
	//���ѭ������str��ʼλ�ã�һֱ����ƶ�ֱ��\0
	while (*str)
	{
		//��������ָ��������㷵���ַ�����ʼ��ַ
		const char *p = str;
		const char *q = sub_str;
		//�ڲ�ѭ�������ж�str�ַ����Ƿ����sub_str�Ӵ�
		while ((*p == *q)&&*p&&*q)
		{

			p++;
			q++;
		}
		//���sub_strɨ�赽\0˵����str���ҵ��Ӵ�������str�е��Ӵ����ַ�����ʼ��ַ
		if (*q == '\0')
		{
			return str;
		}
		str++;
	}


	return NULL;

}

//1.ģ��ʵ��memcpy
void * my_memcpy(void * dst, const void * src, size_t num)
{
	//�ж�ָ��Ϸ���
	assert(dst != NULL);
	assert(src != NULL);

	//��void *ǿ������תΪchar *�����㰴�ֽڿ���
	char *_dst = (char *)dst;
	const char * _src = (const char *)src;

	//����num���ֽ�
	while (num)
	{
		*_dst = *_src;
		_dst++;
		_src++;
		num--;
	}

	return dst;


}

//2.ģ��ʵ��memmove
void *my_memmove(void *dst, const void *src, size_t num)
{
	//�ж�ָ��Ϸ���
	assert(dst != NULL);
	assert(src != NULL);

	//��void *ǿ������תΪchar *�����㰴�ֽڿ���
	char *_dst = (char *)dst;
	const char * _src = (const char *)src;

	//���3�������󿽱�
	if (_dst > _src && _dst < _src + num)
	{
		//������dst��srcָ�����ұ�
		_dst = _dst + num - 1;
		_src = _src + num - 1;

		//����num���ֽ�
		while (num)
		{
			*_dst = *_src;
			_dst--;
			_src--;
			num--;
		}
	}
	//�������ȫ���������ҿ���
	else
	{
		//����num���ֽ�
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
	//�ڴ治�ص�
	//char dst = "12cde";
	//char *src = "ab123";
	//my_memcpy(&dst, &src,strlen(src));
	////memcpy(&dst, &src, strlen(src));
	//printf("%s\n", src);
	//�ڴ��ص�
	//char buf[16] = "abcdef";
	//my_memcpy(buf + 1, buf, strlen(buf)+1);
	//printf("%s\n", buf);

	////2.
	////�ڴ��ص�
	//char buf[16] = "abcdef";
	//my_memmove(buf + 1, buf, strlen(buf) + 1);
	//printf("%s\n", buf);

	//4.�⺯����֤
	char buf1[16] = "abcdef";
	memcpy(buf1 + 1, buf1, strlen(buf1)+1);
	printf("�⺯��memcpy��%s\n", buf1);

	char buf2[16] = "abcdef";
	memmove(buf2 + 1, buf2, strlen(buf2) + 1);
	printf("�⺯��memove��%s\n", buf2);


	////5.
	//char *str = "abcd adef abcde123 fg";
	//char *sub_str = "de123";
	//printf("%s\n", my_strstr(str, sub_str));

	system("pause");
	return 0;
}