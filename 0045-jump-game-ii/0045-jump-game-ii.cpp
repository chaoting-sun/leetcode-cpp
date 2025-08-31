class Solution {
public:
    int backtrack(vector<int>& nums, int start, vector<int> &memo) {
        int n = nums.size();

        // base case
        if (start == n - 1) return 0;
        if (nums[start] == 0) return INT_MAX; // unreachable
    
        if (memo[start] != -1) return memo[start];

        int min_length = INT_MAX;
        int furthest_jump = min(n - 1, start + nums[start]);
        for (int end = start + 1; end <= furthest_jump; end++) {
            int curr_length = backtrack(nums, end, memo);
            if (curr_length != INT_MAX) {
                min_length = min(min_length, 1 + curr_length);
            }
        }
        return memo[start] = min_length;
    }
    
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1); // -1 -> not computed
        int min_length = backtrack(nums, 0, memo);
        return min_length == INT_MAX ? 0 : min_length;
    }
};
