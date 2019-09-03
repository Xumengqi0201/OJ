/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


/*暴力搜索，搜索成功后直接退出两重循环，有时间复杂度为O(N)的算法，需要借助map*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
        for (int i=0;i<nums.size()-1;i++){
            int tmp = target-nums[i];
            for (int j=i+1;j<nums.size();j++){
                if (nums[j]==tmp){
                    res.push_back(i);
                    res.push_back(j);
                    goto re:;
                }
            }
        }
        re:
        return res;
    }
};