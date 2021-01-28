#include"sort.h"

//交换数据
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

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
	//2.比较n-1趟
	for (int i = 0; i <n-1; ++i)
	{
		//1.第1趟排序，从第1个元素开始到n-1个元素结束,比较n-1次
		for (int j = i; j < n-1-i; ++j)
		{
			//如果左边大于右边，则交换位置
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
		PrintArr(a, n);
	}

}

// 冒泡排序优化
void BubbleSort1(int* a, int n)
{
	
	//2.比较n-1趟
	for (int i = 0; i <n - 1; ++i)
	{
		int exchange = 0;
		//1.第1趟排序，从第1个元素开始到n-1个元素结束,比较n-1次
		for (int j = i; j < n - 1 - i; ++j)
		{
			//如果左边大于右边，则交换位置
			if (a[j] > a[j + 1])
			{
				exchange = 1;
				Swap(&a[j], &a[j + 1]);
			}
		}
		PrintArr(a, n);
		if (exchange == 0)
			break;
	}

}

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
			return left;
		else if (a[mid] < a[right])
			return right;
		else
			return mid;
		
	}
	else if (a[right] > a[left])
	{
		if (a[mid] > a[right])
			return right;
		else if (a[mid] < a[left])
			return left;
		else
			return mid;
	}
	else
	{

	}
}

// 快速排序递归实现
// 快速排序hoare版本,左右指针法
int PartSort1(int* a, int left, int right)
{
	//三数取中解决有序，
	//begin mid right
	//int midIndex = GetMidIndex(a, left, right);
	//Swap(&a[midIndex], a[left]);
	

	//1.选择关键值用于划分区间，选左值作为key	
	int keyindex = left;
	//2.选左值让右边先走，优先找到最小值，左右交换，最后将左值与key交换
	while (left < right)
	{
		//右边先找小,找到就停下来
		while (left < right && a[right] >= a[keyindex])
		{
			--right;
		}
		//左边找到大的停下来
		while (left < right && a[left] <= a[keyindex])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyindex], &a[left]);

	return left;

}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	return 0;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyindex = right;
	int prev = left-1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[cur], &a[++prev]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	//1.先划分区间
	int div = PartSort3(a, left, right);
	//2.判断左右区间是否有序
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}


