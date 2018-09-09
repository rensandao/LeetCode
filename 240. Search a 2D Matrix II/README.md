### 描述
```
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following 
properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.    Given target = 20, return false.
```


### 思路
* 利用一维的二分查找的思想解决二维的查找？题目给出两个关键属性，从这两个属性考虑。
  考虑行与列的条件限制，在每一行执行二分查找。



### 代码


### 知识点
