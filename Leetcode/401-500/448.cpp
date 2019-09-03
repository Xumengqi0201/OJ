class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector <int> ans;
		for (int i = 0; i < nums.size(); i++){
			int val = abs(nums[i])-1;
			if (nums[val] > 0){
				//不能改变数字的绝对值
				nums[val] = -nums[val];
			}
		} 
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] > 0)	ans.push_back(i+1);
		}
		return ans;      
    }
};

/*
	这个题难在不能有extra space并且时间复杂度为O(n),
	所以哈希表什么的不用考虑了，只能想办法在遍历数组的时候给出现过的数字进行标记

*/