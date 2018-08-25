## 描述
```
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

示例：

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不能含有重复的三元组。

## 思路

180824 老实说光审题，我都要半天。 

这里要找的是数组中的值，而非下标。

要解决：1.三个元素的取值问题；2.符合条件的三个值得存储问题；

* 先从小到大排序，明确数据之间大小的关系。a<=b<=c；
* 三个变量问题转换两个问题，就可以借鉴two sum中的思想；
* 第一个变量从0-n，另外两个使用`前后夹逼准则`；


## 代码
