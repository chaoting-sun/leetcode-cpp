
class Solution {
public:
    // Approach: DP - state machine
    // dp[i + 1]: the maximum profit to the ith day
    //  - sold[i] = held[i-1] + prices[i]
    //  - held[i] = max(held[i-1], rest[i-1] - prices[i])
    //  - rest[i] = max(rest[i-1], sold[i-1])

    // Time: O(n)
    // Space: O(n)

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<int> sold(n, 0), held(n, 0), rest(n, 0);

    //     sold[0] = INT_MIN; // impossible condition
    //     held[0] = -prices[0];
    //     rest[0] = 0;

    //     for (int i = 1; i < n; i++) {
    //         sold[i] = held[i - 1] + prices[i];
    //         held[i] = max(held[i - 1], rest[i - 1] - prices[i]);
    //         rest[i] = max(rest[i - 1], sold[i - 1]);
    //     }

    //     return max(sold[n - 1], rest[n - 1]);
    // }

    // Time: O(n)
    // Space: O(1)

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int sold = INT_MIN;
        int held = -prices[0];
        int rest = 0;

        for (int i = 1; i < n; i++) {
            int next_sold = held + prices[i];
            held = max(held, rest - prices[i]);
            rest = max(rest, sold);

            sold = next_sold;
        }

        return max(sold, rest);
    }
};

// state machine: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75928/share-my-dp-solution-by-state-machine-thinking
// s0: rest
// s1: held
// s2: sold
// rest[i] = max(rest[i - 1], sold[i - 1]);
// held[i] = max(held[i - 1], rest[i - 1] - prices[i]);
// sold[i] = held[i - 1] + prices[i];
