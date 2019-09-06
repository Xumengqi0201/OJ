class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector <int> ans;
    	if (matrix.size() == 0 || matrix[0].size() == 0)	return ans;
 		int left = 0, right = matrix[0].size()-1;
 		int up = 0, down = matrix.size()-1;
 		while (left <= right && up <= down){
 			for (int i = left; i<= right; i++){
 				ans.push_back(matrix[up][i]);
 			}
 			for (int i = up+1; i<= down; i++){
 				ans.push_back(matrix[i][right]);
 			}
 			//一定要加上down > up 否则，会重复打印
 			for (int i = right-1; i >= left && down > up; i--){
 				ans.push_back(matrix[down][i]);
 			}
 			//加上left <right,否则会重复打印
 			for (int i = down-1; i > up && left < right; i--){
 				ans.push_back(matrix[i][left]);
 			}
 			left++;
 			right--;
 			up++;
 			down--;
 		}   	
 		return ans;
    }
};
/*
	顺时针打印矩阵，记录上下左右四个边界位置

*/