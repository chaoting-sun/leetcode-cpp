class Solution {
public:
    // Approach: DP. once we know the cost to the (n - 2)th and (n - 1)th stairs, we know the answer
    // Time: O(n)
    // Space: O(n)
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};