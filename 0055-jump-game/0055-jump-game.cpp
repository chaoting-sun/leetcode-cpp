class Solution {
public:
    bool backtrack(vector<int>& nums, int pos, vector<int>& memo) {
        int n = nums.size();
        if (pos == n - 1) return true;

        if (memo[pos] != -1) return memo[pos] == 1 ? true : false;

        for (int i = 1; i <= nums[pos]; i++) {
            int new_pos = pos + i;
            // invalid destination
            if (new_pos >= n) continue;
            if (backtrack(nums, new_pos, memo)) {
                memo[pos] = 1;
                return true;
            }
        }
        memo[pos] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        return backtrack(nums, 0, memo);
    }
};