class Solution {
private:
    int rob_in_range(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n);
        dp[start] = nums[start];
        for (int i = start + 1; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int max1 = rob_in_range(nums, 0, n - 2);
        int max2 = rob_in_range(nums, 1, n - 1);
        return max(max1, max2);
    }
};

// test case: nums = [2,4,3] -> 4
// trace:
// n = 3
// max1 = rob_in_range(nums, 0, 1)
//  - dp = [0 2 0 0]
//  - for loop: 2 - 1
//  < returns 2
// max2 = rob_in_range(nums, 1, 2)
//  - dp = [0 0 4 0]
//  - for loop: 3 - 2
//  < returns 4
// < returns 4
