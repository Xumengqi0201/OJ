class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() ==0)  return 0;
        int peak = prices[0], valley = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.size()-1;){
        	while (i < prices.size()-1 && prices[i] >= prices[i+1]){
        		i++;
        	}
        	valley = prices[i];
        	while(i < prices.size()-1 && prices[i] <= prices[i+1]){
        		i++;
        	}
        	peak = prices[i];
        	maxProfit += peak-valley;
        }
        return maxProfit;
    }
};
//这个easy的题真不会，没想出来，注意i的边界条件