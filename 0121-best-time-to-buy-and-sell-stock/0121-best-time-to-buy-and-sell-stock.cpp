class Solution {
public:
    // Approach1: loop the prices and keep updating the min. prices and max. profits.
    // Time: O(n)
    // Space: O(1)

    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - min_price;
            max_profit = max(max_profit, profit);
            min_price = min(min_price, prices[i]);
        }

        return max_profit;
    }
};