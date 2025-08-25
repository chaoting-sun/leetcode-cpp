class Solution {
public:
    // Approach: DP
    // dp[i][j]: the number of possible unique paths to (i,j)
    // intialization: dp[i][0] = 0, dp[i][0] = 1, dp[0][j] = 1
    // state transition function: dp[i][j] = dp[i-1][j] + dp[i][j-1]

    // Time: O(mn)
    // Space: O(mn)

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};