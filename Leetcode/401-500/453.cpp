class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
        	if (nums[i] < min)	min = nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
        	ans += nums[i]-min;
        }
        return ans;
    }
};



/*
	同样是不看答案打死想不出来。
	最基本的思路倒是很简单，一次move等于把n-1个数字加1，要用最小的move次数
	使得最终所有的数字相等。那么每次必然是选择最小的n-1的数字加1。
	按照这个思路的话，怎么选择最小的n-1的数字呢，难道是排序。。。。
	ummmm肯定不行的，会超时

	所以，要换一下，一次同时把n-1个最小的数字+1相当于把最大的数字-1。重复这个
	操作一直到所有的数字相等就是最终的move次数
	所以只要计算每一个数字和最小的数字之间的差值再相加就好了。
	晕。。。。


*/