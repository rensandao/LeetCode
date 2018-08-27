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
    * 三个元素sum！=target时，查找到s1<target和s2>target，比较s1和s2。

## 代码


