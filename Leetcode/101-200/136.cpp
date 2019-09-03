class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	unordered_set<int> S;
    	int sum = 0;
    	for (int i = 0; i < nums.size(); i++){
    		S.insert(nums[i]);
    		sum += nums[i];
    	}
    	int sum1 = 0;
    	unordered_set<int> ::iterator it = S.begin();
    	for (; it != S.end(); it++){
    		sum1 += *it;
    	}
    	return 2*sum1-sum;     
        
    }
};
/*
	set去重，数学方法求解
	
*/
