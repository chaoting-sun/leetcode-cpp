class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] * nums[i];
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] * nums[i];

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int res = 1;
            if (i > 0) res *= prefix[i - 1];
            if (i < n - 1) res *= suffix[i + 1];
            ans[i] = res;
        }
        return ans;
    }
};