class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int misnum = 0;
        vector <int> v(nums.size()+1, 0);
        for (int i = 0;i < nums.size(); i++){
        	v[nums[i]] = 1;
        }
        for (int i = 0; i < v.size() ; i++){
        	if (v[i] == 0){
        		misnum = i;
        		break;
        	}
        }
        return misnum;
    }
};
//1.hash:fast but cost space  2.sort:slow but save space

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	if (nums[nums.size()-1] != nums.size())		return nums.size();
    	if (nums[0] != 0)	return 0;
    	for (int i = 0; i < nums.size()-1; i++){
    		int expect = nums[i]+1;
    		if (expect != nums[i+1])	return expect;
    	}
    	return 0;
        
    }
};