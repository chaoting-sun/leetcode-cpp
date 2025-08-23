class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp0(n + 1), dp1(n + 1);
        dp0[1] = nums[0];
        for (int i = 2; i < n; i++) {
            dp0[i] = max(dp0[i - 2] + nums[i - 1], dp0[i - 1]);
        }
        for (int i = 2; i <= n; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);
        }
        return max(dp0[n - 1], dp1[n]);
    }
};
