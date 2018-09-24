/*
排序的顺序表存储结构 + 交换元素函数
*/

#define MAXSIZE 10
typedef struct
{
  int r[MAXSIZE+1];   //注意：r[0]用作哨兵或临时变量
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
    for(j=L->Length-1; j>=i;j--) // j=i时，比较j[i]和j[i+1]的值，如j[1]与j[2]
    {
      if(L->r[j]>L->r[j+1])
      {
        swap(L,j,j+1);
      }
    }
  }
}

//3.冒泡排序优化
void BubbleSort2(SqList *L)[
{
  int i,j;
  Status flag=TRUE;
  for(i=1; i<L->Length && flag; i++)  //flag为true，则退出循环。
  {
    flag = FALSE;
    for(j=L->Length-1; j>=i; j--)
    {
      if(L->r[j] > L->r[j+1])
      {
        swap(L,j,j+1)
        flag = TRUE;     //只要有数据交换，则flag更新为TRUE.
      }
    }
  }
}


/*
算法复杂度： 1+2+3+...+(n-1) = n(n-1)/2 次，即O（n^2）
*/
