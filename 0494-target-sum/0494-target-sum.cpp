class Solution {
public:
    int backtrack(vector<int>& nums, int target, int i, int curr_sum) {
        if (i == nums.size()) {
            return curr_sum == target ? 1 : 0;
        }

        return backtrack(nums, target, i + 1, curr_sum + nums[i]) +
               backtrack(nums, target, i + 1, curr_sum - nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, target, 0, 0);
    }


    // definition of dp[i][j]: the number of expressions we can build to target i from nums[0] to nums[j]
    // state transition function: dp[i][j] = dp[i][]

    // int findTargetSumWays(vector<int>& nums, int target) {
        
    // }
};