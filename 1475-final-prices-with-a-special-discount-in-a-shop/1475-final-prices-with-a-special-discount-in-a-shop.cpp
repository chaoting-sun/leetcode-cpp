class Solution {
public:
    // Approach: Monotonic Stack (strictly increasing stack)
    // Time: O(n)
    // Space: O(n)

    vector<int> finalPrices(vector<int>& prices) {
        int num_prices = prices.size();
        if (num_prices == 0) return {};

        stack<int> index_stack;
        vector<int> final_prices(num_prices);

        for (int i = 0; i < num_prices; i++) final_prices[i] = prices[i];
        for (int i = 0; i < num_prices; i++) {
            while (!index_stack.empty() && prices[index_stack.top()] >= prices[i]) {
                final_prices[index_stack.top()] -= prices[i];
                index_stack.pop();
            }
            index_stack.push(i);
        }
        return final_prices;
    }
};
