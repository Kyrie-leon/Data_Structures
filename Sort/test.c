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
	//int a[] = { 6,25,24,9,12,55,56};
	int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, n - 1);
	printf("-----------");
	PrintArr(a, n);
	BubbleSort1(a, n);
	PrintArr(a, n);
}

void TestQuickSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	//int a[] = { 2,4,7,2,6,4,5,7,8,32,33,11 };
	int n = sizeof(a) / sizeof(a[0]);

	PrintArr(a, n);
	QuickSort(a, 0, n - 1);
	PrintArr(a, n);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	system("pause");
	return 0;
}