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
1. 参考
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<=0) return false;  // 语句判断要放在最前面，不然会报错：reference binding to null pointer of type 'value_type'
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();
        //if(matrix.size()<=0) return false;   //放在这一行就会报错。
        
        int low =0, high =m*n, mid;
        while(low<high){
            mid = low+(high-low)/2;
            int v=matrix[mid/n][mid%n];   //666
            if(v==target)
                return true;
            else if(v > target)
                high=mid;   //此处为什么不能写成 mid-1 ?
            else
                low =mid+1;
        }     
        return false;
    }
};
```



### 知识点
* 二维数组读取
* [vector::begin 与 vector::front的区别](https://blog.csdn.net/liangzhaoyang1/article/details/51853686)
  [vector::front](http://www.cplusplus.com/reference/vector/vector/front/)
  bigin和end返回的是迭代器，是指针；而front和back则返回的是引用，由于引用没有指定类型，所以在需要考虑类型的情况下有未定义的问题。

* [size_t](http://www.cplusplus.com/reference/cstddef/size_t/?kw=size_t) 无符号整型类型名，类似int等。属于c库里（衰）
* [报错：reference binding to null pointer of type 'value_type'](https://blog.csdn.net/m0_38088298/article/details/79249044)
