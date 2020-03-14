/*
	solution1 : O(n2), O(1)
	不借助数据结构

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector <int> ans;
        for (int i = 0; i < nums.size(); i++){
        	int number1 = nums[i];
        	for (int j = i+1; j < nums.size(); j++){
        		if (target - number1 == nums[j]){
        			ans.push_back(i);
        			ans.push_back(j);
        			return ans;
        		}
        	}
        }

        return ans;
    }
};

/*
	solution2 :O(n),O(n)
	unordered_map利用哈希表实现，插入和搜索的时间复杂度为O(1)

	
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector <int> ans;
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++){
        	nums_map.insert(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++){
        	int number = target-nums[i];
        	//注意，同一个位置的元素不能用两次
        	if (nums_map.find(number) != nums_map.end() && i != nums_map[number]){
        		ans.push_back(i);
        		ans.push_back(nums_map[number]);
        		break;
        	}
        }

        return ans;
    }
};