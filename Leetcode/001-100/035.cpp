
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size(), pos = 0; //初始化为0
        for (int i = 0; i < len; i++){
            if (nums[i] == target){ //找到这个数返回下标
                pos = i;
                break;
            }
            //当前这个数比目标小，那么目标的插入位置肯定在这个数后面
            else if (nums[i] < target)  pos = i+1;
            //当前这个数比目标大，那么目标的插入位置肯定在这个数前面。终止遍历跳出循环
            else  break;
        }
        return pos;
    }
};