class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right){
        	long mid = left +(right-left)/2;  
        	//mid设置成long型，如果设成int型在下一行mid*mid，仍然按照int计算会溢出的
        	long tmp = mid *mid;
        	//
        	if (tmp == num)		return true;
        	else if (tmp < num)	 left = mid+1;
        	else right = mid-1;
        }
        return false;
    }
};