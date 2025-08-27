class Solution {
public:
    // Approach: Backtracking -> bad (Time = 2^n)

    // int backtrack(vector<int>& nums, int target, int i, int curr_sum) {
    //     if (i == nums.size()) {
    //         return curr_sum == target ? 1 : 0;
    //     }

    //     return backtrack(nums, target, i + 1, curr_sum + nums[i]) +
    //            backtrack(nums, target, i + 1, curr_sum - nums[i]);
    // }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return backtrack(nums, target, 0, 0);
    // }

    // Approach: Backtracking + memoization

    // # of ways to finish from index i to end to reach target
    // int backtrack(vector<int>& nums, int target, vector<unordered_map<int, int>>& memo, int i, int curr_sum) {
    //     if (i == nums.size()) {
    //         return curr_sum == target ? 1 : 0;
    //     }

    //     if (memo[i].count(curr_sum)) return memo[i][curr_sum];
        
    //     memo[i][curr_sum] = backtrack(nums, target, memo, i + 1, curr_sum + nums[i]) +
    //                         backtrack(nums, target, memo, i + 1, curr_sum - nums[i]);
    //     return memo[i][curr_sum];
    // }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<unordered_map<int, int>> memo(nums.size());
    //     return backtrack(nums, target, memo, 0, 0);
    // }

    // Approach: DP
    // dp[i][j]: the number of methods for the first i number to yield j
    // state transition function
    // Time: O(n * target)
    // Space: O(n * target)

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0] = 1; // (0 element, 0 sum)

        for (int i = 0; i < n; i++) {
            for (auto &p: dp[i]) {
                int curr_sum = p.first;
                int curr_cnt = p.second;
                dp[i + 1][curr_sum - nums[i]] += curr_cnt;
                dp[i + 1][curr_sum + nums[i]] += curr_cnt;
            }
        }

        return dp[n][target];
    }
};