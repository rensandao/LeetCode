## 描述
```
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

示例
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
给定一个整数数组和一个目标值，找出数组中求和为目标值的两个数的索引。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。



## 思路
1.用什么结构去做？

对数组中任意两个数进行相加，结果等于target，来判别
分析：
1. 数组用vector来存储；为何？
2. 要解决如何实现数组任意两个数相加，采用什么样的数据结构？
   暴力相加，用两组for实现；
  （但是限定条件又说了：数组中的两元素相加结果没有重复现象发生，但是同一个元素不能用两次！意味着每次挑选两个，再换2个。）（第一次看产生误导理解）


Skill Logs：

1.180824 能想到的就是 暴力查找，两个for循环；但要注意边界。

2.用hash表。因为复杂度O(n)。需要了解unordered_map。


## 代码

方法1： 暴力，时间复杂度O[n*(n-1)], 空间复杂度O(1)。会超时？
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size()-1; i++){
              for(int j=i+1; j<nums.size(); j++){
                  if( nums[i] == target-nums[j] ){
                      result.push_back(i);
                      result.push_back(j);
                      return result;
                  }
              }
        }
    }
};
```
方法2： hash表查找

