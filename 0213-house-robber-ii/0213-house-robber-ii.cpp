class Solution {
public:
    // Approach: DP
    // Time: O(n)
    // Space: O(n)

    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 1) return nums[0];

    //     vector<int> dp0(n + 1), dp1(n + 1);
    //     dp0[1] = nums[0];
    //     for (int i = 2; i < n; i++) {
    //         dp0[i] = max(dp0[i - 2] + nums[i - 1], dp0[i - 1]);
    //     }
    //     for (int i = 2; i <= n; i++) {
    //         dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);
    //     }
    //     return max(dp0[n - 1], dp1[n]);
    // }

    // Approach: DP with O(1) space
    // Time: O(n)
    // Space: O(1)

    int getMaxRob(vector<int>& nums, int left, int right) {
        int prev_max = 0;
        int curr_max = nums[left];

        for (int i = left + 1; i <= right; i++) {
            int next_max = max(prev_max + nums[i], curr_max);
            prev_max = curr_max;
            curr_max = next_max;
        }
        return curr_max;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int max0 = getMaxRob(nums, 0, n - 2);
        int max1 = getMaxRob(nums, 1, n - 1);
        return max(max0, max1);
    }
};
