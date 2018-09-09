### 描述
```
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following 
properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```

### 思路
* 



### 代码



### 知识点
* 二维数组读取
* [vector::begin 与 vector::front的区别](https://blog.csdn.net/liangzhaoyang1/article/details/51853686)
  [vector::front](http://www.cplusplus.com/reference/vector/vector/front/)
  bigin和end返回的是迭代器，是指针；而front和back则返回的是引用，由于引用没有指定类型，所以在需要考虑类型的情况下有未定义的问题。


