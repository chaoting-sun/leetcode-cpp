class Solution {
public:
    // Approach: Backtracking + memoization
    // Time: O(n^2) in the worst case (when all nums[i] are large, like n, and recursion explores almost all jumps)
    // Space: O(n)

    // bool backtrack(vector<int>& nums, int pos, vector<int>& memo) {
    //     int n = nums.size();
    //     if (pos == n - 1) return true;

    //     if (memo[pos] != -1) return memo[pos] == 1 ? true : false;

    //     int furthest_jump = min(pos + nums[pos], n - 1);
    //     for (int next_pos = pos + 1; next_pos <= furthest_jump; next_pos++) {
    //         if (backtrack(nums, next_pos, memo)) {
    //             memo[pos] = 1;
    //             return true;
    //         }
    //     }
    //     memo[pos] = 0;
    //     return false;
    // }

    // bool canJump(vector<int>& nums) {
    //     vector<int> memo(nums.size(), -1);
    //     return backtrack(nums, 0, memo);
    // }

    // Approach: DP
    // Time: O(n^n)
    // Space: O(n)

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<bool> dp(n, false);
    //     dp[n - 1] = true;

    //     for (int i = n - 2; i >= 0; i--) {
    //         int furthest_jump = min(i + nums[i], n - 1);
    //         for (int j = i + 1; j <= furthest_jump; j++) {
    //             if (dp[j]) {
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }

    //     return dp[0];
    // }

    // Approach: Greedy Approach
    // from current destination (dest), we search from dest - 1 back to check if any position
    // can jump to dest. if we find it, then set it to be dest and recurse the implementation
    // Time: O(n)
    // Space: O(n)

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dest = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= dest) {
                dest = i;
            }
        }
        return dest == 0;
    }
};