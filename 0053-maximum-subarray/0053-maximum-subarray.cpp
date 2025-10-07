class Solution {
public:
    // Approach: Kadane's Algorithm (DP)
    //
    // We scan from left to right and keep the best subarray sum that MUST end at the current position.
    // Define dp[i] as the maximum subarray sum that ends at nums[i-1] (note: dp is 1-based to match the code).
    // Transition:
    //   dp[i] = max(nums[i-1], dp[i-1] + nums[i-1])
    //           ^ start new at i-1    ^ extend the previous best that ended at i-2
    //
    // While filling dp, track a global maximum over all dp[i].
    //
    // Time:  O(n)
    // Space: O(n) in this implementation (can be reduced to O(1) by keeping only the current and global max).


    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     vector<int> dp(n + 1, 0);
    //     dp[1] = nums[0];
    //     int max_sum = dp[1];

    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
    //         max_sum = max(max_sum, dp[i]);
    //     }

    //     return max_sum;
    // }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < n; i++) {
            if (currSum > 0) {
                currSum += nums[i];
            } else {
                currSum = nums[i];
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};