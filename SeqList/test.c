#include "SeqList.h"

//测试头尾插入删除
void TestSeqList1()
{
	//首先定义一个顺序表
	SeqList s;
	//顺序表初始化接口测试
	SeqListInit(&s);
	//顺序表尾插尾删接口测试
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	//头插头删接口测试
	//SeqListPushFront(&s, -1);
	//SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//查找接口测试
	printf("%d\n",SeqListFind(&s, 4));
	//任意位置插入接口测试
	SeqListInsert(&s, 3, 30);
	SeqListPrint(&s);

	//任意位置删除
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	//顺序表销毁
	SeqListDestory(&s);


}


int main()
{
	TestSeqList1();

	return 0;
}