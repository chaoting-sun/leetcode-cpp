class Solution {
public:
    int brust(vector<int>& nums2, int left, int right, vector<vector<int>>& memo) {
        if (left > right) return 0;

        if (memo[left][right] != -1) return memo[left][right];

        int max_coins = 0;
        for (int i = left; i <= right; i++) {
            int coins = nums2[left - 1] * nums2[i] * nums2[right + 1];
            coins += brust(nums2, left, i - 1, memo) + brust(nums2, i + 1, right, memo);
            max_coins = max(max_coins, coins);
        }
        
        return memo[left][right] = max_coins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(n + 2, 1);
        for (int i = 0; i < n; i++) nums2[i + 1] = nums[i];
        
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));

        return brust(nums2, 1, n, memo);
    }
};