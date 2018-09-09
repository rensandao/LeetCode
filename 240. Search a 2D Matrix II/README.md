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
* (1)180909 利用一维的二分查找的思想解决二维的查找？题目给出两个关键属性，从这两个属性考虑。
  考虑行与列的条件限制，在每一行执行二分查找。
* (2) hard code,调用。


### 代码
1. 参考discussion 96ms,O(m * logn)
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {  
        if(matrix.size()==0 || matrix.front().size()==0) return false; // 使用 matrix.empty() 会报错!? 
        const size_t row = matrix.size();
        const size_t col = matrix.front().size();
        
        int i=0;
        while(i<row && target>=matrix[i][0]){
            int low=0, high=col,mid,value;
            while(low<high){
                mid = low+(high-low)/2;
                value = matrix[i][mid];
                if(value==target) return true;
                else if(value> target) high=mid;
                else low=mid+1;   
            }
            ++i;
        }
        return false;
    }
};
```
2. 自己角度





### 知识点


