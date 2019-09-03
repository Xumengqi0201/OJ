class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> hash;
        unordered_map <int, int> :: iterator it;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++){
        	if (hash.find(nums[i]) != hash.end()){
        		if (i-hash[nums[i]] <= k){
        			flag = true;
        			break;
        		}
        		hash[nums[i]] = i;  //存在需要更新元素的位置
        	}
        	else{
        		hash[nums[i]] = i;
        	}
        }
        return flag;
    }
};