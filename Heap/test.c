#include"Heap.h"

void TestHeap()
{
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//
	//HeapSort(a, sizeof(a) / sizeof(HPDataType));
	//HeapPrint(a,sizeof(a)/sizeof(HPDataType));

	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));
	HeapPrint(hp._a, hp._size);
	HeapPush(&hp, 10);
	HeapPush(&hp, 11);
	HeapPush(&hp, 42);
	HeapPrint(hp._a, hp._size);
	HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	//HeapPop(&hp);
	HeapPrint(hp._a, hp._size);
	printf("%d\n",HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));
	HeapDestory(&hp);
	//printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));






}

int main()
{
	TestHeap();

	system("pause");
	return 0;
}