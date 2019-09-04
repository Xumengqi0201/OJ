class Solution {
public:
    int jumpFloor(int number) {
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
/*
	典型的DP，写出转移方程f(n) = f(n-1) + f(n-2)
	初始化f(0) = 0, f(1) = 1, f(2) = 2
	最后一步要么跳两步要么跳一步
 
*/