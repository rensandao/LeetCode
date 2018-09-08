### 描述

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Examples:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

### 思路

180907
* 审题要细致点，要求找到起点和终点的位置。
* 查找问题，要求复杂度O（log n),有序表的三种查找复杂度都是O(log n),可以用尝试先用`二分查找`,也叫`折半查找`。
* 也是分左右两段来找，每段不断折半查找。


### 代码
/*
核心：
利用二分查找，先找到其中的一个target值的位置；
以该位置作为基准，再分别往两段继续查找还有没有target值，如果有的话，则更新下标。
*/

1. 独立分开，调用（超时）


2. 就地寻找左右值
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n=nums.size()-1;
        
        int low=0, high=n;
        while(low<high){          //循环结果一定是到临界位置  
            int mid = (low+high)/2;
            if(nums[mid]>= target)
                high = mid;
            else
                low = mid+1;             
        }
        int start_loc = low;
        
        low=0,high=n;
        while(low<high){
            int mid =(low+high)/2;
            if(nums[mid]<target)
                low = mid+1;
            else
                high = mid;                              
        }
        int end_loc = low;
        
        if(start_loc == end_loc)
            return vector<int>{-1,-1};   
        else
            return vector<int>{start_loc,end_loc};
    
      //  return (start_loc == end_loc) ? vector<int>{-1,-1}:vector<int>{start_loc,end_loc};
        
    }
};




```


### 知识点

* [二分查找复杂度]（）
