// Easier way
// -> go from brute-force method (top down) to dp (bottom up)
// -> think in a reverse way

class Solution {
public:
    // Intuitive: rather than brusting in order, we try to think in reverse order.
    // we start from which is the last to be brusted, and move to the left and right subarray.
    // Also, we add 1 both at left/right most side and handle the central array for easy computation.
    // when we brust ith balloon and goes to the right and left, it is reused to compute the value
    // as it is brusted after all of the balloons in the subarrays
    // Approach: divide and conquer + memoization (top-down)

    // Time: O(n^3)
    // Space: O(n^2)

    // int brust(vector<int>& nums2, int left, int right, vector<vector<int>>& memo) {
    //     if (left > right) return 0;

    //     if (memo[left][right] != -1) return memo[left][right];

    //     int max_coins = 0;
    //     for (int i = left; i <= right; i++) {
    //         int coins = nums2[left - 1] * nums2[i] * nums2[right + 1];
    //         coins += brust(nums2, left, i - 1, memo) + brust(nums2, i + 1, right, memo);
    //         max_coins = max(max_coins, coins);
    //     }
        
    //     return memo[left][right] = max_coins;
    // }

    // int maxCoins(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> nums2(n + 2, 1);
    //     for (int i = 0; i < n; i++) nums2[i + 1] = nums[i];
        
    //     vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));

    //     return brust(nums2, 1, n, memo);
    // }

    // Approach: DP (bottom-up)
    // dp[l][r] = the max coins we get in the subarray if 
    // state transition function: dp[l][r] = max of
    //  - dp[l][l-1] + nums2[l-1] * nums2[l] * nums2[l+1] + dp[l+1][r]
    //  - dp[l][l] + nums2[l] * nums2[l+1] * nums2[l+2] + dp[l+2][r]
    //  - ...
    //  - dp[l][r-1] + nums2[l] * nums2[r] * nums2[l+2] + dp[r+1][r]
    // base case:
    //  - dp[i][i] = nums[i-1] * nums[i] * nums[i+1] where i = 1 ~ n

    // Time: O(n^3)
    // Space: O(n^2)

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(n + 2, 1);
        for (int i = 0; i < n; i++) nums2[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // base case
        for (int i = 1; i <= n; i++) dp[i][i] = nums2[i - 1] * nums2[i] * nums2[i + 1];

        for (int l = n - 1; l >= 1; l--) {
            for (int r = l + 1; r <= n; r++) {
                for (int i = l; i <= r; i++) {
                    dp[l][r] = max(dp[l][r], dp[l][i-1] + nums2[l-1] * nums2[i] * nums2[r+1] + dp[i+1][r]);
                }
            }
        }

        return dp[1][n];
    }
};