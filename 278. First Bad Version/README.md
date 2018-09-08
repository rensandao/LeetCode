### 描述
```
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. Since each version is developed based 
on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes 
all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a 
function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

### 思路
* 最快查找，采用二分查找。 



### 代码
```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1,high=n,mid;
        while(low<=high){
            mid= low + (high-low)/2;  /（low+high)/2有溢出问题。 当low和high的值很大的时候，(low+high)会导致大于溢出值。报错。
            if(isBadVersion(mid))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;         
    }
};
```
### 知识点
* 开始一直写mid=(low+high)/2,本题会导致溢出问题。以后要写成正确版本。
* 相关：题34-35

