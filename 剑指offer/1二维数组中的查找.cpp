/*
	solution 1:最简单的方法

	用每行最右边的元素比较，如果target小于最右边的元素，说明target就在本行；
	如果target大于最右边的元素，说明target还在下一行。
	时间复杂度O（m+n），最坏的情况是数组中的每个元素遍历一遍
	显然这题算法可以改进。

*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	if (array.size() == 0 || array[0].size() == 0)
    		return false;

        int m = array.size(), n = array[0].size();
        for (int i = 0, j = n-1; i < m && j >= 0;){
            int ele = array[i][j];
            if (ele == target)
                return true;
            else if (ele < target)
                i++;
            else 
                j--;
        }
        
    }
};


/*
	solution 2:N行折半法
	对每一行都折半查找,O(m*logn)

*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	if (array.size() == 0 || array[0].size() == 0)
    		return false;
    	
        int m = array.size(), n = array[0].size();
        for (int i = 0; i < m; i++){
            if (array[i][0] <= target && array[i][n-1] >= target){
            	int left = 0, right = n-1;
            	while (left <= right){
            		int mid = left+(right - left)/2;
            		if (array[i][mid] == target) 
            			return true;
            		else if (array[i][mid] < target)
            			left = mid+1;
            		else
            			right = mid-1;

            	}
            }
           
        }
        return false;
        
    }
};

/*
	solution 3:十字分割法
	递归终止条件为区域中只有一个元素

*/
class Solution {
public:
	bool divide(int target, vector<vector<int>> & array, int left, int right, int top , int bottom){
		if (left > right || top > bottom)
			return false;
		if (target < array[top][left] || target > array[bottom][right])
			return false;
		//此时区域中只有一个元素
		if (top == bottom && left == right){
			if (target == array[top][left])
				return true;
			return false;
		}

		//以上条件都不满足，说明target在划分的区域内，对所在区域十字划分
		int vertic = left + (right-left)/2;
		int horiz = top +(bottom-top)/2;
		int ele = array[horiz][vertic];
		if (ele == target) 
			return true;
		//排除左上区域，即每次可以排除1/4区域
		if (target > ele){
			//在右下区域搜索
			if (divide(target, array, vertic+1, right, horiz, bottom))
				return true;
		}
		//在左上区域搜索
		else if (divide(target, array, left, vertic, top, horiz)){
			return true;
		}
		/*无法排除这两个区域，因此每次都要搜索左下和右上两个区域*/
		//在左下区域搜索
		if (divide(target, array, left, vertic, horiz+1, bottom)){
			return true;
		}
		//在右上区域搜
		if (divide(target, array, vertic+1, right, top, horiz-1)){
			return true;
		}

		return false;
		
	}
    bool Find(int target, vector<vector<int> > array) {
    	if (array.size() == 0 || array[0].size() == 0)
    		return false;
    	
       	return divide(target, array, 0, array[0].size()-1, 0, array.size()-1);
        
    }
};