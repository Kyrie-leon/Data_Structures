#include"sort.h"

//��������
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//��ӡ����
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
	//Ĭ�ϵ�һ�����Ѿ�������
	for (int i = 0; i < n-1; ++i)
	{
		int end=i;	//�����������һ��Ԫ�ص��±�
		int tmp = a[end + 1]; //������Ԫ�ش�����ʱ����tmp
		while (end >= 0)
		{

			if (tmp < a[end])			//���������Ԫ�ر�end�±��Ԫ��С
			{
				a[end + 1] = a[end];	//1.end�±�Ԫ�����Ų����tmp�Ĳ���
				--end;					//2.end���ƽ�����һ�ֵıȽ�
			}
			else                        //���������Ԫ�ش��ڻ����end�±��Ԫ���˳�ѭ��
			{
				break;
			}
		}
		a[end + 1] = tmp;				//��tmp���뵽���鵱��
	}
}


// ϣ������
void ShellSort(int* a, int n)
{
	//1.gap>1ʱΪԤ���������и��ӽ�����
	//2.gap=1Ϊֱ�Ӳ������򣬱�֤����
	int gap = n;	
	while (gap > 1)
	{
		gap = gap / 3 + 1;					//ͨ����
		int gap = 4;
		for (int i = 0; i < n - gap; ++i)	//i��0��ʼ��n-gap����
		{
			int end = i;			
			int tmp = a[end + gap];			//ÿ������gap�Ĳ�����Ϊ����Ԫ��
			while (end >= 0)
			{
				if (tmp < a[end])			//���������Ԫ�ر�end�±��Ԫ��С
				{
					a[end + gap] = a[end];	//1.end�±�Ԫ�����Ų����tmp�Ĳ��룬����endŲ���Ĳ�����gap������1��
					end -= gap;				//2.end���ƽ�����һ�ֵıȽϣ�ͬ������gap����
				}
				else                        //���������Ԫ�ش��ڻ����end�±��Ԫ���˳�ѭ��
				{
					break;
				}

				a[end + gap] = tmp;				//��tmp���뵽���鵱��
			}
		}
	}
	
}


// ������

void AdjustDwon(int* a, int n, int root)
{
	//���µ����㷨�������������
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����нϴ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		//���ڵ���ϴ�ĺ��ӽڵ�Ƚϣ����С�ں��ӽڵ㣬�򽻻�
		if (a[parent] < a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			//���¸��ڵ���ӽڵ�
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
	//1.���ѣ������㷨�����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	//2.����ÿ��ִ�����µ�������С��Ԫ�ص��������Ȼ��ɾ����Ԫ�ؼ�������
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[0];
		a[0] = a[end];
		a[end] = tmp;
		AdjustDwon(a, end, 0);	//ÿ�δӸ��ڵ㿪ʼִ�����µ����㷨
		--end;
	}
}

// ð������
void BubbleSort(int* a, int n)
{	
	//2.�Ƚ�n-1��
	for (int i = 0; i <n-1; ++i)
	{
		//1.��1�����򣬴ӵ�1��Ԫ�ؿ�ʼ��n-1��Ԫ�ؽ���,�Ƚ�n-1��
		for (int j = i; j < n-1-i; ++j)
		{
			//�����ߴ����ұߣ��򽻻�λ��
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
		PrintArr(a, n);
	}

}

// ð�������Ż�
void BubbleSort1(int* a, int n)
{
	
	//2.�Ƚ�n-1��
	for (int i = 0; i <n - 1; ++i)
	{
		int exchange = 0;
		//1.��1�����򣬴ӵ�1��Ԫ�ؿ�ʼ��n-1��Ԫ�ؽ���,�Ƚ�n-1��
		for (int j = i; j < n - 1 - i; ++j)
		{
			//�����ߴ����ұߣ��򽻻�λ��
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

//����ȡ��
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

// ��������ݹ�ʵ��
// ��������hoare�汾,����ָ�뷨
int PartSort1(int* a, int left, int right)
{
	//����ȡ�н������
	//begin mid right
	//int midIndex = GetMidIndex(a, left, right);
	//Swap(&a[midIndex], a[left]);
	

	//1.ѡ��ؼ�ֵ���ڻ������䣬ѡ��ֵ��Ϊkey	
	int keyindex = left;
	//2.ѡ��ֵ���ұ����ߣ������ҵ���Сֵ�����ҽ����������ֵ��key����
	while (left < right)
	{
		//�ұ�����С,�ҵ���ͣ����
		while (left < right && a[right] >= a[keyindex])
		{
			--right;
		}
		//����ҵ����ͣ����
		while (left < right && a[left] <= a[keyindex])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyindex], &a[left]);

	return left;

}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	return 0;
}

// ��������ǰ��ָ�뷨
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

	//1.�Ȼ�������
	int div = PartSort3(a, left, right);
	//2.�ж����������Ƿ�����
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}


