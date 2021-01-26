#include"sort.h"


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

	for (int i = 0; i < n - 1; ++i)
	{
		//1 һ�����򣬴ӵ�һ������ʼ�ͺ�������ֱȽ�
		for (int j = i; j < n - 1 - i; ++j)
		{
			//���������ð
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// ��������
void CountSort(int* a, int n)
{
	//1.�ҳ������������Сֵ

	//2.
}

