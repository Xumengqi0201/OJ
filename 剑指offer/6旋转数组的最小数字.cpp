class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)	return 0;
        int lo = 0, hi = rotateArray.size()-1;
        while (rotateArray[lo] == rotateArray[hi]){
            lo++;
            hi--;
        }
        //lo 和 hi中间被分割了不在非递减数组内
        while (rotateArray[lo] > rotateArray[hi]){
            int mid = lo + (hi-lo)/2;
            if (rotateArray[lo] >= rotateArray[mid]){
                lo = mid+1;
            }
            else if (rotateArray[high] >= rotateArray[mid]){
                hi = mid;
            }
        }
        return rotateArray[lo];
    }
};

/*
    原数组是非递减数组，那么旋转过后分为两块，都还是非递减数组。
    有序数组查找采用二分查找，最后一定可以找到最低点lo。


*/