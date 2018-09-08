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
* 180908 对比第35题，这里考虑的重点是，要找的值存在且有多个问题；


### 代码
/*
核心：
利用二分查找，先找到其中的一个target值的位置；
以该位置作为基准，再分别往两段继续查找还有没有target值，如果有的话，则更新下标。
*/

1. 独立分开，调用（超时）
```
class Solution {
public:
      
    int Binary_Search(vector<int>& nums, int low, int high, int target){
        int mid;
        while(low <= high){
            mid = (low + high) /2;  // 折半
            if( target < nums[mid])
                high = mid -1;      //若查找目标值小于中值，则最高位等于mid下调一位
            else if(target > nums[mid])
                low = mid +1;       // 反过来，上调最低位下标
            else
                return mid;               
            }
        return -1;
    }  
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int loca = Binary_Search(nums, 0, n, target);
        
        vector<int> result; 
        int low=-1, high=-1;
        if(loca >0){
            low=loca;
            high=loca;
            
            int temp1=low; //low postion
            do{
                low = temp1;
                temp1 = Binary_Search(nums,0,low-1,target);
            }while(temp1>=0);  //一直在低区域找target，直到没有，返回-1，跳出循环体。low值最终锁定在上一次下标值。
            
            int temp2=high;
            do{
                high = temp2;
                temp2 = Binary_Search(nums, 0, high+1, target);
            }while(temp2<=n);  
        }   
            
            result.push_back(low);
            result.push_back(high);
            return result; 
    }
};
```
修改后：
```
class Solution {
public:
         
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int loca = Binary_Search(nums, 0, n, target);
        
        vector<int> result; 
        int low=-1, high=-1;
        if(loca >=0){  //漏掉=0情况
            low=loca;
            high=loca;
            
            int temp1=low; //low postion
            do{
                low = temp1;
                temp1 = Binary_Search(nums,0,low-1,target);
            }while(temp1>=0);  //一直在低区域找target，直到没有，返回-1，跳出循环体。low值最终锁定在上一次下标值。
            
            int temp2=high;
            do{
                high = temp2;
                temp2 = Binary_Search(nums, high+1, n, target);  //这里的范围弄错了
            }while(temp2>=0);  //temp>=2,写成了temp<=n;逻辑混了。
        }   
            
            result.push_back(low);
            result.push_back(high);
            return result; 
    }
    
     int Binary_Search(vector<int>& nums, int low, int high, int target){
        int mid;
        while(low <= high){
            mid = low+(high-low) /2;  // 折半
            if( target < nums[mid])
                high = mid -1;      //若查找目标值小于中值，则最高位下标下调
            else if(target > nums[mid])
                low = mid +1;       // 反过来，上调最低位下标
            else
                return mid;               
            }
        return -1;
    }  
    
};

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
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n, mid,start_loc,end_loc;
        while(low<high){          //这里的临界位置甚至问题？ low<high 以及n=nums.size()的关系！
            mid = (low+high)/2;
            if(nums[mid]>= target)
                high = mid;
            else
                low = mid+1;             
        }
        start_loc = low;
    
        low=0;
        high=n;
        while(low<high){
            mid =(low+high)/2;
            if(nums[mid] > target)
                high = mid;  
            else
                low = mid+1;                            
        }
        end_loc = low;

        return (start_loc == end_loc) ? vector<int>{-1,-1} : vector<int>{start_loc,end_loc-1};
    }
};
```

### 知识点

* [二分查找复杂度]（）
