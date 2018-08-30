/*斐波那契查找  利用黄金分割原理

复杂度为O(logn),平均性能要高于折半查找。如果是最坏情况，查找效率则要低于折半查找。
另外,
折半查找运算是进行加法与除法运算：mid=(low+high)/2,
插值查找是复杂的四则运算：mid=low+(high-low)*(key-a[low])/(a[high]-a[low]),
斐波那契查找是最简单的加减法运算： mid=low+F[k-1]-1;

在海量数据查找，细微差别会影响最终查找效率。
三种有序表的查找本质上是分割点的选择不同，各有优劣。

*/


int Finbonacci_Search(int *a, int n, int key)
{
  int low, high, mid, i, k;
  low=1;
  high=n;
  k=0;
  while(n>F[k]-1)     //最高下标对应的斐波那契数列的位置
    k++;
  for(i=n;i<F[k]-1;i++)
    a[i]=a[n];
  
  while(low<=high)
  {
    mid = low+F(k-1)-1;   //找到黄金分割位，下标；
    if(key<a[mid])        //key与该黄金分割位置的值
    {
      high = mid -1;     //数组的最高位下标
      k=k-1;             //斐波那契数列的下标减一位
    }
    else if(key>a[mid])
    {
      low=mid+1;       
      k=k-2;
    }
    else
    {
      if(mid<=n)
        return mid;
      else
        return n;
    }
  }
  return 0;

}
