### 描述

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2


### 思路
* 查找+定位； 查找用二分查找，如果有其值，则能迅速锁定；那么生下来的就是当没有其target时，如何定位问题？
* 对象第34题，本题侧重考虑没有target情况下的定位问题；第35则是考虑有多个target时的定位。算是简化版。

2.

### 代码

### 知识点
