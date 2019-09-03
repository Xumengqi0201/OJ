/*
	最大子列和问题，常用的两种方法：在线处理和分治法
	1.在线处理：O(n),浙大数据结构公开课一开始就介绍了这种方法
	2.分治法：O(nlogn),最大子列三种情况，结果取三种情况下最大的数。
	  a.最大子列再左半边的序列中
	  b.最大子列在右半边的子列中
	  c.最大子列横跨左半边和右半边的序列。先计算左半边包含左半边最右边的元素的子列和，再计算右半边包含右半边左边第一个元素的子列和，将二者相加即可。

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//maxsum不能设为0，有可能数组里都是负数
    	int maxsum = nums[0], maxtmp = 0;
        for (int i = 0; i < nums.size(); i++){
            maxtmp += nums[i];
            maxsum = max(maxsum, maxtmp);
            if (maxtmp < 0){
                maxtmp = 0;
            }

        }
        return maxsum;
        
    }
};

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        return conquer_approch(nums, 0, nums.size()-1);
    }

    int conquer_approch(const vector<int> &nums, int left, int right) {
        if (left == right)  return nums[left];

        int center = (left + right) / 2;
        int maxLeft = conquer_approch(nums, left, center);
        int maxRight = conquer_approch(nums, center + 1, right);

        int maxLeftBorder = nums[center], Ltmp = nums[center];
        for (int i = center - 1; i >= left; i--) {
            Ltmp += nums[i];
            maxLeftBorder = max(maxLeftBorder, Ltmp);
        }

        int maxRightBorder = nums[center + 1], Rtmp = nums[center + 1];
        for (int i = center + 2; i <= right; i++) {
            Rtmp += nums[i];
            maxRightBorder = max(maxRightBorder, Rtmp);
        }

        return max(max(maxLeft, maxRight), maxRightBorder + maxLeftBorder);
    }
};