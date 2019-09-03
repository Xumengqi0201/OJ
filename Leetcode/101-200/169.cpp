class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> hash;
        int res;
        for (int i = 0;i < nums.size(); i++){
        	hash[nums[i]] = hash[nums[i]]+1;
        	if (hash[nums[i]] > nums.size()/2){
                res = nums[i];
                break;
            }
        	
        }
        return res;
    }
};