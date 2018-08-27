## 描述
```
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is 
closest to target. Return the sum of the three integers. You may assume that each input would have exactly 
one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```



## 思路

1. 跟题1、15思路雷同，先排序后前后夹逼原则；
2. 找到边界问题：
    * 三个元素sum=target；
    * 三个元素sum！=target时，查找到s1<target和s2>target，比较s1和s2。（思路不严谨）
    * 针对上面差值gap比较，应该简化为谁的gap小就保留谁，再继续跟其他比较。
    

## 代码

1. 排序+夹逼原则，复杂度O(n^2).
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=0;
        int min_gap=INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int a=nums[i];
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                int b=nums[j];
                int c=nums[k];
                int sum=a+b+c;
                
                if(sum==target){
                    return target;
                }
                if(abs(target-sum)<min_gap){            //此处的min_gap 设计可以再考虑更简洁点
                    min_gap = abs(target-sum);
                    result = sum;
                }
                if(sum < target){
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
                if(sum > target){
                    while(j<k && nums[k]==nums[k-1]) k--;
                    k--;
                }       
            }
        }
        return result;
    }
};
```

## 知识点

1. INT_MAX

   INT_MIN在标准头文件limits.h中定义：
   ```
   #define INT_MAX 2147483647
   #define INT_MIN (-INT_MAX - 1)
   ```
   [reference](https://blog.csdn.net/TwT520Ly/article/details/53038345)

