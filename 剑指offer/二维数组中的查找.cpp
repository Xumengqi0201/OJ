class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0)	return false;
		int m = array.size(), n = array[0].size();
		int i = 0, j = n-1;
		while(i < m && j >=0){
			int ele = array[i][j];
			if (ele == target)	return true;
			else if (ele < target){
				i++;
			}
			else{
				j--;
			}
		}
		return false;

    }
};

/*
	题目描述
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
	判断数组中是否含有该整数。

	取一行的最右边的元素，如果该元素小于target，那么行+1，否则列-1;，可以通过。
*/
