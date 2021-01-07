#include "stack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack * ps)
{
	assert(ps);
	ps->_a = (STDataType *)malloc(sizeof(Stack) * 4);	//Ĭ�������СΪ4
	ps->_top = 0;		//ջΪ�գ���ջ��Ϊ0
	ps->_capacity = 4;	//Ĭ��ջ������Ϊ4
}

//��ջ
void StackPush(Stack * ps, STDataType data)
{
	assert(ps);
	//�ж�ջ�Ƿ����ˣ�����������
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;	//ÿ������2��
		STDataType * tmp = (STDataType *)realloc(ps->_a, sizeof(Stack)*ps->_capacity);
		//�ж��ڴ��Ƿ�����ɹ�
		if (NULL == tmp)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		ps->_a = tmp;
	}
	//��ջ
	ps->_a[ps->_top] = data;	
	ps->_top++;
}

//��ջ
void StackPop(Stack * ps)
{
	assert(ps);
	assert(ps->_top>0);
	ps->_top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack *ps)
{
	assert(ps);
	assert(ps->_top>0);

	return ps->_a[ps->_top-1];	
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack * ps)
{
	assert(ps);
	return ps->_top;
}

//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط�0����Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !(ps->_top);
}

//����ջ
void StackDestory(Stack * ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}