class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k %= nums.size();
         myreverse(nums, 0, nums.size()-1);
         reverse(nums,0,k-1);
         reverse(nums,k, nums.size()-1);
    }
    void myreverse(vector<int> &nums, int start, int end){
    	while(start < end){
    		int tmp = nums[start];
    		nums[start] = nums[end];
    		nums[end] = tmp;
    		start++;
    		end--;
    	}
    }
};

//找到规律三步逆转nums中的元素