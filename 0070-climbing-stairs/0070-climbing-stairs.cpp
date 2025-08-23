class Solution {
public:
    // Approach: DP

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp(1 + n);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};