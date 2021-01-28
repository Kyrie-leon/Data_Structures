#include <stdio.h>

void PrintArr(int* a, int n)
{
  for(int i = 0; i < n; ++i)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
}

void Swap(int* px, int* py)
{
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

void BubbleSort1(int* a, int n)
{
  //排n趟就可以让数组有序
  int end=n-1;
  while(end>0)
  {
    //一趟排序，从第一个元素开始到n-1个元素结束，
     for(int j = 0; j<n-1; ++j)
     {
        //如果左边大于右边，就交换
        if(a[j]>a[j+1])
        {
          Swap(&a[j],&a[j+1]);
        }
     }
     --end;

    PrintArr(a,n);
  }
}


void BubbleSort2(int* a, int n)
{
  //n-1趟排序
  for(int i = 0; i < n-1; ++i)
  {
    //每一趟比较n-i-1次
    for(int j=0; j<n-i-1; ++j)
    {
      if(a[j]>a[j+1])
      {
        Swap(&a[j],&a[j+1]);
      }
    }

    PrintArr(a,n);
  }
}

void BubbleSort(int* a, int n)
{
  //n-1趟排序
  for(int i = 0; i < n-1; ++i)
  {
    int flag = 0; //设置flag
    //每一趟比较n-i-1次
    for(int j=0; j<n-i-1; ++j)
    {
      if(a[j]>a[j+1])
      {
        flag = 1; //如果该趟排序发生交换，flag置1
        Swap(&a[j],&a[j+1]);
      }
    }
    PrintArr(a,n);
    //一趟排序过后没有发生变化，说明数组已经有序
    if(flag == 0)
      break;
  }
}


int main()
{
  int a[] = {25,6,56,24,9,12,55};
  int b[] = {25,6,56,24,9,12,55};
  int c[] = {25,6,56,24,9,12,55};
  int n = sizeof(a)/sizeof(a[0]);
  printf("-----BubbleSort------\n");
  BubbleSort(a,n);
  printf("-----BubbleSort1------\n");
  BubbleSort1(b,n);
  printf("-----BubbleSort2------\n");
  BubbleSort2(c,n);
   //PrintArr(a,n);
  return 0;
}
