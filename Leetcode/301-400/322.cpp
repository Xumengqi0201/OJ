class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      //int *f = new int[amount+1];
  	int f[100] = { 0 };
      f[0] = 0;
      for (int i = 1; i <= amount; i++){
        f[i] = INT_MAX;
        for (int j = 0; j < coins.size(); j++){
          if (i >= coins[j] && f[i-coins[j]] != INT_MAX){
            f[i] = min(f[i-coins[j]]+1, f[i]);
          }
        }
      }

      if (f[amount] == INT_MAX){
        f[amount] = -1;
      }
      int res = f[amount];
      //delete []f;

      return res;    
    }
};

/*
  这是一道典型的动态规划算法题，具有最优子结构性质的问题都可以用DP
  1.确定最优子结构性质：假设问题的最优解是a1,a2,.....ak,即f(amount) = k。
    那么a1,a2,......ak-1必然是f(amount-ak)的最优解
  2.递归定义最优解的值，也就是写出转移方程:
    f(x) =  min(f[x-coins[0]]+1, f[x-coins[1]]+1, ......,f[x-coins[n-1]+1])
    定义初始值f[0] = 0,也就是0元只需要花费0个硬币
  3.按照自底向上的方法计算最优解的值
    本题是从前向后计算
  4.根据计算结果构造一个最优解

  DP算法的步骤都是按照以上四步来的，但是编程的时候需要注意一些细节。比如，
    1.数组的初始值都设为无穷大，因为最终要确定的是一个最小值
    2.数组的下标不能越界
    3.使用INT_MAX这个常量需要#include <climits>
    4.INT_MAX+1会变成INT_MIN，学过CSAPP的都知道，所以在一个数不等于INT_MAX的情况下，才能+1
    5.INT_MAX这个数值表示着f(x)是不能由硬币组合出来。
*/