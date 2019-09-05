class Solution {
public:
    int rectCover(int number) {
    	if (number <= 2)	return number;
    	int *dp = new int[number+1];
    	dp[0] = 0, dp[1] = 1, dp[2] = 2;
    	for (int i = 3; i <= number; i++){
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    	int ans = dp[number];
    	delete []dp;
    	return ans;

    }
};
//DP
