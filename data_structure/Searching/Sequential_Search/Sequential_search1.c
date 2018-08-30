/*查找的第一种方法：顺序表
顾名思义，顺序查找
*/

//1. 顺序查找，O(n)
int Sequential_Search(int*a,int n,int key)
{
  for(int i=0;i<n;i++)
  {
    if(a[i]==key)
      return i;
  }
  return 0;
}


//2.优化, 减少中间要比较的消耗， O(n)
int Sequential_Search2(int *a, int n, int key)
{
  int i;
  a[0]=key;
  i=n;
  while(a[i] != key)
  {
    i--;
  }
  return i;
}
