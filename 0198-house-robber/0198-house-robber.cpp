class Solution {
public:
    // Approach: DP
    // state transition function: dp[i] = max(dp[i-2] + nums[i], dp[i-1])
    // - dp[i-2] + nums[i]: rob i
    // - dp[i-1]: not rob i
    // Time: O(n)
    // Space: O(n)

    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 1) return nums[0];

    //     vector<int> dp(n + 1);
    //     dp[1] = nums[0];

    //     for (int i = 1; i < n; i++) {
    //         dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
    //     }

    //     return dp[n];
    // }

    // Approach: Two variables maintaining the prev max and curr max money
    // Time: O(n)
    // Space: O(1)

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev_max = 0;
        int curr_max = nums[0];

        for (int i = 1; i < n; i++) {
            int next_max = max(prev_max + nums[i], curr_max);
            prev_max = curr_max;
            curr_max = next_max;
        }

        return curr_max;
    }
};