class Solution {
public:
    bool backtrack(vector<int>& nums, int pos, vector<int>& memo) {
        if (pos == nums.size() - 1) return true;

        if (memo[pos] != -1) return memo[pos] == 1 ? true : false;

        for (int i = 1; i <= nums[pos]; i++) {
            if (backtrack(nums, pos + i, memo)) {
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