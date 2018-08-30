## 描述
```
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

```
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 2^31 - 1 。


## 思路

1.先排序后夹逼查找。

## 代码

 1. 先排序后查找，利用upper_bound和lower_bound.
 ```
 class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result=0;
        vector<int> sum1;
        for(int i=0; i<A.size();i++){
            for(int j=0; j<B.size();j++){
                 sum1.push_back(A[i]+B[j]);
            }
        }
        
        vector<int> sum2;
        for(int m=0;m<C.size();m++){
            for(int n=0;n<D.size();n++){
                sum2.push_back(C[m]+D[n]);
            }
        }
        
        sort(sum2.begin(), sum2.end()); 
        for(int i=0; i<sum1.size();i++){
            int target = -sum1[i];
            result += upper_bound(sum2.begin(),sum2.end(), target) - lower_bound(sum2.begin(),sum2.end(), target); 
        }
        return result;
    }
};
 ```
 
 2. 利用unordered_map的键-值对，存储和查找。散列表hash.
 ```
 class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> sum1;
        
        for(auto a:A){
            for(auto b:B){
                ++sum1[a+b];
            }
        }
        int result=0;
        for(auto c:C){
            for(auto d:D){
                auto it=sum1.find(-(c+d));   // 0 or 1
                if(it !=sum1.end()){
                    result+= it->second;     // accumulate
                }
            }
        }
        return result;
    }
};
 ```

## 知识点

1. upper_bound
2. unordered_map
