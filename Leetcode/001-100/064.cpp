class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       	if (grid.size() == 0 || grid[0].size() == 0){
       		return 0;
       	}
       	int m = grid.size(), n = grid[0].size();
       	vector <vector <int> > dp(m , vector<int>(n));
       	//注意一下二维vector的构造函数
       	for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == 0 && j == 0){
					dp[i][j] = grid[i][j];
				}
				else if (i == 0){
					dp[i][j] = dp[i][j-1] + grid[i][j];
				}
				else if (j == 0){
					dp[i][j] = dp[i-1][j] + grid[i][j];
				}
				else{
					dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
				}
			}
		}

		return dp[m-1][n-1];
    }

};
/*
	一开始暴力搜索超时了，算出了所有的从起点到终点的路径和并求他们的最小值
	后来想到这是一个明显的动态规划问题，因为它具有最优子结构性质。
	用一个二维数组记录对应当前的最小路径和，最后直接返回最下面和最右边的数就好了。


*/