class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0, leastBuyDay = prices[0];
        for(int i = 0; i < prices.size(); i++){
            leastBuyDay = min(leastBuyDay, prices[i]);
            maximumProfit = max(maximumProfit, prices[i] - leastBuyDay);
        }
        return maximumProfit;
    }
};
