## 描述
```
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```
给定含n个整数的数组nums和一个整数target,数组nums中是否存在a,b,c,d满足a+b+c+d=target？ 找到他们。

注意：结果中不能包含重复的组。


## 思路

总的思想仍是：先排序，后前后夹逼准则。

方式上分两种：

* 利用3sum的轮子，加一个for循环；
* 两个for循环，再两个数前后夹逼；



## 代码
1.180817 两个for，前后夹逼。  检测不完整。

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int a=nums[i];
            int j=i+1;
            
            for(;j<n-2;j++){
                int b=nums[j];
                while(j>i && nums[j]==nums[j+1]) j++;
                int k=j+1;
                int m=n-1;
                
                while(k<m){
                    int c=nums[k];
                    int d=nums[m];
                    int sum=a+b+c+d;
                    
                    if(sum<target){
                        while(k<m && nums[k]==nums[k+1]) k++;
                        k++;                  
                    }else if(sum>target){
                        while(m>k && nums[m]==nums[m-1]) m--;
                        m--;  
                    }else{
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        
                        while(k<m && nums[k]==nums[k+1]) k++;
                        while(m>k && nums[m]==nums[m-1]) m--;
                        
                        k++;
                        m--;
                    }   
                }
            }
            
        } 
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;   
    }
};
```



## 知识点

1. auto(result.begin(), result.end())

2. result.erase(unique(result.begin(), result.end()), result.end())
