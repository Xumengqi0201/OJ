/*
	第一种解法，O(n2),需要优化一下
	第二种解法，O(n),随时更新maxprofit和minprice，因为maxprofit更新的地方一定是当前price-minprice
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 0; i < prices.size();i++){
			for (int j = i+1; j < prices.size(); j++){
				res = max(res, prices[j]-prices[i]);
			}
		}
		return res;        
    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		int minPrice = INT_MAX;
		for (int i = 0; i < prices.size();i++){
			minPrice = min(minPrice, prices[i]);
			maxProfit = max(prices[i]-minPrice, maxProfit);
		}
		return maxProfit;        
    }
};