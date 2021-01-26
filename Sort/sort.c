#include"sort.h"


//打印数组
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	//默认第一个数已经是有序
	for (int i = 0; i < n-1; ++i)
	{
		int end=i;	//有序数组最后一个元素的下标
		int tmp = a[end + 1]; //待插入元素存入临时变量tmp
		while (end >= 0)
		{

			if (tmp < a[end])			//如果待插入元素比end下标的元素小
			{
				a[end + 1] = a[end];	//1.end下标元素向后挪方便tmp的插入
				--end;					//2.end左移进行下一轮的比较
			}
			else                        //如果待插入元素大于或等于end下标的元素退出循环
			{
				break;
			}
		}
		a[end + 1] = tmp;				//将tmp插入到数组当中
	}
}


// 希尔排序
void ShellSort(int* a, int n)
{
	//1.gap>1时为预排序，让数列更接近有序
	//2.gap=1为直接插入排序，保证有序
	int gap = n;	
	while (gap > 1)
	{
		gap = gap / 3 + 1;					//通常的
		int gap = 4;
		for (int i = 0; i < n - gap; ++i)	//i从0开始到n-gap结束
		{
			int end = i;			
			int tmp = a[end + gap];			//每次增加gap的步长作为插入元素
			while (end >= 0)
			{
				if (tmp < a[end])			//如果待插入元素比end下标的元素小
				{
					a[end + gap] = a[end];	//1.end下标元素向后挪方便tmp的插入，这里end挪动的不长是gap而不是1了
					end -= gap;				//2.end左移进行下一轮的比较，同理左移gap步长
				}
				else                        //如果待插入元素大于或等于end下标的元素退出循环
				{
					break;
				}

				a[end + gap] = tmp;				//将tmp插入到数组当中
			}
		}
	}
	
}


// 堆排序

void AdjustDwon(int* a, int n, int root)
{
	//向下调整算法，建大堆排升序
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中较大的
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		//父节点与较大的孩子节点比较，如果小于孩子节点，则交换
		if (a[parent] < a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			//更新父节点和子节点
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int* a, int n)
{
	//1.建堆，升序算法建大堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	//2.排序，每次执行向下调整将最小的元素调整到最后，然后删除该元素继续调整
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[0];
		a[0] = a[end];
		a[end] = tmp;
		AdjustDwon(a, end, 0);	//每次从根节点开始执行向下调整算法
		--end;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{	

	for (int i = 0; i < n - 1; ++i)
	{
		//1 一趟排序，从第一个数开始和后面的数字比较
		for (int j = i; j < n - 1 - i; ++j)
		{
			//将大数向后冒
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// 计数排序
void CountSort(int* a, int n)
{
	//1.找出数组中最大最小值

	//2.
}

