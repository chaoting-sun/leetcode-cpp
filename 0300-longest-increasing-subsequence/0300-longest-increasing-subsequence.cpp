class Solution {
// Approach: DP
// dp[i]: the number of strictly increasing subsequence end at i
// dp[i] = nums[i - 1] >= nums[i] ? dp[i - 1] else dp[i - 1] + 1

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);
        int max_length = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        };

        return max_length;
    }
};