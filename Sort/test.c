#include"sort.h"


void TestInsertSort()
{
	int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintArr(a, n);
	InsertSort(a, n);
	PrintArr(a, n);
}
void TestShellSort()
{
	int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintArr(a, n);
	ShellSort(a, n);
	PrintArr(a, n);
}

void TestHeapSort()
{
	int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintArr(a, n);
	HeapSort(a, n);
	PrintArr(a, n);
}

void TestBubbleSort()
{
	int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintArr(a, n);
	BubbleSort(a, n);
	PrintArr(a, n);
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	TestBubbleSort();
	system("pause");
	return 0;
}