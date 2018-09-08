### 描述

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2


### 思路
* 查找+定位； 查找用二分查找，如果有其值，则能迅速锁定；那么生下来的就是当没有其target时，如何定位问题？
* 对象第34题，本题侧重考虑没有target情况下的定位问题；第35则是考虑有多个target时的定位。算是简化版。


### 代码

1.
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){          //循环到临界位置  
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target)
                    high = mid-1;   //如果大于target，则高位减1。  注意：这里有个疑问，受第34题影响，开始写成high=mid？ 但是就是报超时！
            else
                low = mid+1;             
        }
        return low;   
    }
``` 


### 知识点
