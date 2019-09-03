class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastzero = 0;
        for (int i = 0; i < nums.size(); i++){
        	if (nums[i] != 0){
        		nums[lastzero++] = nums[i];
        	}
        }
        for (int i = lastzero; i < nums.size(); i++){
        	nums[i] = 0;
        }
    }
};
//把一个数组中的０元素全部移动到最后，不改变其他元素的相对顺序