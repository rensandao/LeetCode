// 简单选择排序

void SelectSort(SqList *L)
{
 int i,j,min;
 for(i=1;i<L->length;i++)
 {
  min = i;
  for(j=i+1;j<L->length;j++)
  {
    if(L->r[min] > L->r[j])
      min = j;
  }
  if(i!=min)
    swap(L,i,min);
 } 
}


/*
特点：交换移动数据次数很少，节约时间。
比较次数：最差最好情况都是一样多，n(n-1)/2
交换次数： 最好0次，最差n-1次

基于比较和交换次数总和，总时间复杂度为O(n^2).

对于冒泡排序同为O(n^2)，简单选择排序性能要略优。
*/
