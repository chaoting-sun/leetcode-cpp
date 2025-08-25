class Solution {
public:
    // Approach: DP
    // dp[i][j] = True/False. if we can pick from first i numbers to get the sum j
    // initialization: dp[0][0] = T
    // for i, if we don't pick it, then dp[i][j] = dp[i - 1][j]
    //        if we pick it, then dp[i][j] = nums[i] + dp[i - 1][j - nums[i]]

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        
        int sum = 0;
        for (int v: nums) sum += v;
        if (sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int j = 1; j <= target; j++) dp[0][j] = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};

