### 描述
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

### 思路

*

### 代码

1. 二分查找。但是这里的处理逻辑为何是反过来的？ 
```
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low=1, high=n, mid;
        while(low<=high){
            mid = low+(high-low)/2;
            if(guess(mid)==0)
                return mid;
            else if (guess(mid)==1)
                low = mid+1;   //此处的逻辑是反过来的。 
            else
                high = mid-1;
        }
        
    }
};
```

改进：
```
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) <= 0) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
```

### 知识点
