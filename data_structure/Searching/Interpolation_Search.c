/* interpolation search, O(logn) 
 适合用表长交大，而关键字分布均匀
*/
int Interplolation_Search(int*a, int n, int key)
{
  int low, high,mid;
  low=1;
  high=n;
  while(low<high)
  {
    mid = low+(high-low)*(key-a[low])/(a[high]-a[low]); /*插值,其他与二分插值代码一样*/
    if(key<m[mid])
      high=mid-1;
    else if(key>a[mid])
      low=mid+1;
    else
      return mid;
  }
  return 0;
}
