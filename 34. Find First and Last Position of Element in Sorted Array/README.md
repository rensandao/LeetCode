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



### 知识点

* [二分查找复杂度]（）
