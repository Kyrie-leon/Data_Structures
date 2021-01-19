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

// ѡ������
void SelectSort(int* a, int n)
{

}

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);