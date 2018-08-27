## 描述
```
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```
给定含n个整数的数组nums和一个整数target,数组nums中是否存在a,b,c,d满足a+b+c+d=target？ 找到他们。

注意：结果中不能包含重复的组。


## 思路

总的思想仍是：先排序，后前后夹逼准则。

实现方法：

1. 两个for循环，再两个数前后夹逼；

*2. 利用3sum的轮子，加一个for循环；

*3. map缓冲

*4. mutimap

*5. upper_bound()  对比问题

## 代码
1.180817 两个for，前后夹逼。  检测不完整。

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int a=nums[i];
            int j=i+1;
            
            for(;j<n-2;j++){
                int b=nums[j];
                while(j>i && nums[j]==nums[j+1]) j++;
                int k=j+1;
                int m=n-1;
                
                while(k<m){
                    int c=nums[k];
                    int d=nums[m];
                    int sum=a+b+c+d;
                    
                    if(sum<target){
                        while(k<m && nums[k]==nums[k+1]) k++;
                        k++;                  
                    }else if(sum>target){
                        while(m>k && nums[m]==nums[m-1]) m--;
                        m--;  
                    }else{
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        
                        while(k<m && nums[k]==nums[k+1]) k++;
                        while(m>k && nums[m]==nums[m-1]) m--;
                        
                        k++;
                        m--;
                    }   
                }
            }
            
        } 
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;   
    }
};
```

2. 借鉴
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        for(auto a=nums.begin();a<prev(nums.end(),3);++a){     //对比上段数组下标表示法，使用auto和指针*a，*b,*c,*d能简化不少代码 
            for(auto b=next(a);b<prev(nums.end(),2);++b){  
                auto c=next(b);
                auto d=prev(nums.end());
                while(c<d){
                    auto sum=*a+*b+*c+*d;
                    if(sum<target){
                        ++c;                  
                    }else if(sum>target){
                        --d;  
                    }else{
                        result.push_back({*a, *b, *c, *d});
                        ++c;
                        --d;
                    }   
                }
            }
        } 
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());    //unqique(): Remove consecutive duplicates in range
        return result;   
    }
};
```

## 知识点

1. [auto()](https://www.cnblogs.com/KunLunSu/p/7861330.html)  

2. [std::prev(nums.end(),2)](https://en.cppreference.com/w/cpp/iterator/prev)

   *[延伸](https://www.cnblogs.com/zhoutaotao/p/3833249.html)

3. [std::unique()](http://www.cplusplus.com/reference/algorithm/unique/)

4. [std::vector::erase()](http://www.cplusplus.com/reference/vector/vector/erase/)

5. [std::upper_bound](http://www.cplusplus.com/reference/algorithm/upper_bound/)


