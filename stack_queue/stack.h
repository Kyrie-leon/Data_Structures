#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>

#define N 10
typedef int STDataType;
typedef struct Stack Stack;
//struct Stack
//{
//	STDataType a[N];
//	int _top;	//栈顶
//};

//支持动态增长的栈
struct Stack
{
	STDataType * _a;
	int _top;			//栈顶
	int _capacity;		//容量
};

//初始化栈
void StackInit(Stack * ps);

//入栈
void StackPush(Stack * ps, STDataType data);

//出栈
void StackPop(Stack * ps);

//获取栈顶元素
STDataType StackTop(Stack *ps);

//获取栈顶中有效元素个数
int StackSize(Stack * ps);

//检测栈是否为空，如果为空返回非0，不为空返回0
int StackEmpty(Stack* ps);

//销毁栈
void StackDestory(Stack * ps);
