class Solution {
public:
    // Approach: DP
    // Time: O(n)
    // Space: O(n)

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = j - 3; i < j; i++) {
                if (i < 0) continue;
                dp[j] = min(dp[j], dp[i] + costs[j-1] + (j - i)*(j - i));
            }
        }
        return dp[n];
    }

    
};