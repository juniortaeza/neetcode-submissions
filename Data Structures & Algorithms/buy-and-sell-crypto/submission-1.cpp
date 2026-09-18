class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, leastBuyDay = prices[0];
        for(int price : prices){
            leastBuyDay = min(leastBuyDay, price);
            maxProfit = max(maxProfit, price - leastBuyDay);
        }
        return maxProfit;
    }
};
