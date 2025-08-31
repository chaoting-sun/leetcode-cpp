class Solution {
public:
    // Approach: Backtracking + Memoization
    // Time: O(n^2)
    // Space: O(n)

    // int backtrack(vector<int>& nums, int start, vector<int> &memo) {
    //     int n = nums.size();

    //     // base case
    //     if (start == n - 1) return 0;
    //     if (nums[start] == 0) return INT_MAX; // unreachable
    
    //     if (memo[start] != -1) return memo[start];

    //     int min_length = INT_MAX; // unreachable
    //     int furthest_jump = min(n - 1, start + nums[start]);
    //     for (int end = start + 1; end <= furthest_jump; end++) {
    //         int curr_length = backtrack(nums, end, memo);
    //         if (curr_length != INT_MAX) {
    //             min_length = min(min_length, 1 + curr_length);
    //         }
    //     }
    //     return memo[start] = min_length;
    // }
    
    // int jump(vector<int>& nums) {
    //     vector<int> memo(nums.size(), -1); // -1 -> not computed, INT_MAX -> unreachable
    //     int min_length = backtrack(nums, 0, memo);
    //     return min_length == INT_MAX ? 0 : min_length;
    // }

    // Approach: Greedy
    // Time: O(n)
    // Space: O(1)

    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;

        while (r < n - 1) {
            int tmpr = INT_MIN;
            for (int i = l; i <= r; i++) {
                int furthest_jump = min(i + nums[i], n - 1);
                tmpr = max(tmpr, furthest_jump);
            }
            
            if (tmpr == r) return 0;
            
            l = r + 1;
            r = tmpr;
            ans++;
        }
        return ans;
    }

};
