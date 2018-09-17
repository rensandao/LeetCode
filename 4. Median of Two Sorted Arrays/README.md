###描述
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
  
  （1）采取对两个数组进行分割的做法，基本保证: 
       
       a.两组数组分割线的左侧的数目等于右侧的；
       b.左侧的数据最大值要小于或等于右侧最小值；
  

### 代码

### 知识点
