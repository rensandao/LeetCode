## 描述
```
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

示例：

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不能含有重复的三元组。

## 思路

180824 老实说光审题，我都要半天。 

这里要找的是数组中的值，而非下标。

要解决：1.三个元素的取值问题；2.符合条件的三个值得存储问题；

* 先从小到大排序，明确数据之间大小的关系。a<=b<=c；
* 三个变量问题转换两个问题，就可以借鉴two sum中的思想；
* 第一个变量从0-n，另外两个使用`前后夹逼准则`；


## 代码

1. 先排序，再前后夹逼。but, 检测时超时Time Limit Exceeded.

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            while(i>0 && nums[i-1]==nums[i]) continue;  //skip duplication 满足（）内部情况则跳过去。
            int a = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            
            if(nums[j]+nums[k] == a){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                
                result.push_back(temp);
                while(j<k && nums[j]==nums[j+1]) j++;
                while(k>j && nums[k]==nums[k+1]) k--;
                    
                j++;
                k--;    //由于已经排好序了，当nums[j]+nums[k]==a符合时，j和k一定同时夹逼移动来查找新的匹配位置项。
                
            }else if(nums[j]+nums[k]<a){
                while(j<k && nums[j]==nums[j+1]) j++;
                j++;               
            }else{
                while(k>j && nums[k]==nums[k+1]) k--;
                k--;
            }
        }
        return result;
    }
};
```
20180827 修改
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        if (nums.size() < 3) return result; // 要判断数组长度，不然即使测试ok，commit也可能会有错误
                                            //Error: reference binding to null pointer of type 'value_type
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;  //skip duplication 满足（）内部情况则跳过去。
            int a = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k){
                if(nums[j]+nums[k] == a){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);

                    result.push_back(temp);
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(k>j && nums[k]==nums[k-1]) k--;  //此处应为k-1，惯性导致。

                    j++;
                    k--;    //由于已经排好序了，当nums[j]+nums[k]==a符合时，j和k一定同时夹逼移动来查找新的匹配位置项。

                }else if(nums[j]+nums[k]<a){
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;               
                }else{
                    while(k>j && nums[k]==nums[k-1]) k--;  //k-1
                    k--;
                }
            }
        }
        return result;
    }
};



```
