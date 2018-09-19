### 描述
```
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

```


### 思路  

* 中位数如何求？ 即排序中间的数，如果总数是偶数，取中间两个数的平均值。
* 两个数组虽然已经是排好序的，但是两组数量大小不一定一样。最难的点是这两组之间的排序如何解决，关键的的分界点在哪？
如何列举出来nums1和nums2的可能关系，大概有6种。但是肯定不能分开单独做，而是要找到一种方法解决这种分界问题。
  
  （1）采取对两个数组进行分割的做法，
  
       [a[0],a[1],····a[i]  |  a[i+1],a[i+2],···,a[m-1]]
       [b[0],b[1],···,b[j]  |  b[j+1],b[j+2],···,b[n-1]]
       
       左侧的数量 M=(i+1+j+1)
       
       右侧的数量 N=(m-1-i)+(n-1-j)
       
       首先保证: 
       
       a.两组数组分割线的左侧的数目等于右侧的,或相差为1。可规定m+n为奇数时，左侧数量M=N-1。方便后续取值。
       b.左侧的数据最大值要小于或等于右侧最小值。a[i]<=b[j+1] && b[j]<=a[i+1]。
      
      如果满足这两个条件，则相当于把两组数组均分开来。最终取中间数。
      
      那么如何实现？第一个问题是查找问题。即要先查找到i，j的位置。
      
      二分查找：
      a[i] = Binary_Search(nums1)
      b[j] = Binary_Search(nums2)
      
      
  
### 代码
  方法1: 参照Solutuion
  ```
  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m =nums1.size(), n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        //if(m>n) {swap(nums1, nums2); swap(m, n);}
        
        //binary search
        int low=0,high=m;
        while(low<=high){   //等号何时加何时不加？
            
            int i= (low+high)/2;
            int j= (m+n+1)/2-i;
            
            if(i>0 && nums1[i-1]>nums2[j]){ 
                high = i-1;
            }
            else if(i<m && nums1[i]<nums2[j-1]){
                low = i+1;
            }
            else{                                 //几个边界问题处理
                double left_max;
                if(i==0) left_max = nums2[j-1];
                else if(j==0) left_max = nums1[i-1];
                else left_max = max(nums1[i-1], nums2[j-1]); 
                if( (m+n)%2 ) return left_max;
                
                double right_min;
                if(i==m) right_min = nums2[j];
                else if(j==n) right_min = nums1[i];
                else right_min = min(nums1[i], nums2[j]);
                
                return (left_max + right_min) /2.0;                
            }                 
        }
        return 0.0;       
    }
};
  ```
  
  方法1.1: 对于上述边界问题的代码，简洁性改动(本质上与方法1是一样），但是测试后runtime只有11.7%，68ms。而方法1为36ms。
            说明虽然代码看着简洁，运行速度却不一定。还是方法1更好些。
  ```
  double left_max = (i==0)? nums2[j-1]:(j==0)? nums1[i-1] : max(nums1[i-1],nums2[j-1]);
  double right_min = (i==m)? nums2[j]:(j==n)? nums1[i] : min(nums1[i], nums2[j]);
  return (m+n)%2==1? left_max : (left_max + right_min)/2.0; 
  ```
  方法2： 

### 知识点
 * 关于细节部分需要再理一理。





