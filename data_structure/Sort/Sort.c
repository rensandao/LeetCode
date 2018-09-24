/*
排序的顺序表存储结构 + 交换元素函数
*/

#define MAXSIZE 10
typedef struct
{
  int r[MAXSIZE+1];
  int length;
}SqList;

void swap(SqList *L, int i, int j)
{
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}

// 1. 简单排序实现(冒泡初级版本） 
void BubbleSort(SqList *L)
{
  int i,j;
  for(i=1;i<L->length;i++)
  {
    for(j=i+1;j<L->Length;j++)
    {
      if(L->r[i] > L->r[j])
      {
        swap(L,i,j);
      }
    }
  }
}

//2.冒泡排序（Bubble Sort）
void BubbleSort(SqList *L)
{
  int i,j;
  for(i=1;i<L->Length;i++)
  {
    for(j=L->Length-1; j>=i;j--)
    {
      if(L->r[j]>L->r[j+1])
      {
        swap(L,j,j+1);
      }
    }
  }
}





