/* 折半查找，复杂度O(logn)
具有n个结点的完全二叉树的深度为(log(2)n)+1;
折半查找最坏情况也是。
*/
int Binary_Search(int *a, int n, int key)
{
  int low, high, mid;
  low=1; //最低下标
  high=n;
  while(low<=high)
  {
    mid=(low+high) /2;
    if(key<a[mid])
      high=mid-1;
    else if (key>a[mid])
      low =mid+1;
    else
      return mid;   //mid 即为查找到的位置   此处有bug,比如如果出现多个连续相同数据
  }

  return 0;
}
