class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(),greater<int>());
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; i++){
        	if (nums[i] != nums[i+1])	cnt++;
        	if (cnt == 3)	return nums[i];
        }
        if (cnt == 2)	return nums[nums.size()-1];
        return nums[0];

    }
};
//这个题写了好久，注意一下sort的用法