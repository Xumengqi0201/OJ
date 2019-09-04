class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)	return 0;
        int left = 0, right = rotateArray.size()-1;
        int mid = 0;
        //旋转数组的最左边的数肯定大于等于最右边的数 
        while (rotateArray[left] >= rotateArray[right]){
        	if (left+1 == right)	return rotateArray[right];
        	mid = left + (right-left)/2;
        	//不能确定最小值是在左边子数组还是右边子数组，只能顺序查找
        	if (rotateArray[left] == rotateArray[mid] && rotateArray[left] == rotateArray[right]){
        		int ans = INT_MAX;
        		for (int i = left; i <= right; i++){
        			if (rotateArray[i] < ans)	ans = rotateArray[i];
        		}
        		return ans;
        	}
        	//左边的值比中间值小，那么目标肯定是在left右边
        	else if (rotateArray[left] <= rotateArray[mid]){
        		left = mid;
        	} //左边值比中间值大，那么目标肯定在left左边
        	else{
        		right = mid;
        	}
        }
        return rotateArray[mid];
    }
};