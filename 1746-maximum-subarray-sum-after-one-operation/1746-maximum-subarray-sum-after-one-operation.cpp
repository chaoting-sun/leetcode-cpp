class Solution {
public:
    // Approach: Prefix/Suffix Sum
    // Time: O(n)
    // Space: O(n)

    // int maxSumAfterOperation(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     vector<int> maxPrefixSum(n), maxSuffixSum(n);
    //     int ans = INT_MIN;
        
    //     maxPrefixSum[0] = nums[0];
    //     for (int i = 1; i < n; i++) {
    //         maxPrefixSum[i] = max(maxPrefixSum[i - 1] + nums[i], nums[i]);
    //     }

    //     maxSuffixSum[n - 1] = nums[n - 1];
    //     for (int i = n - 2; i >= 0; i--) {
    //         maxSuffixSum[i] = max(maxSuffixSum[i + 1] + nums[i], nums[i]);
    //     }

    //     for (int i = 0; i < n; i++) {
    //         int curr = nums[i] * nums[i];
    //         if (i > 0) curr = max(curr, curr + maxPrefixSum[i - 1]);
    //         if (i < n - 1) curr = max(curr, curr + maxSuffixSum[i + 1]);
    //         ans = max(ans, curr);
    //     }

    //     return ans;
    // }

    // Approach: Optimized

    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> opUsed(n), opNotUsed(n);
        opNotUsed[0] = nums[0];
        opUsed[0] = nums[0] * nums[0];
        int ans = opUsed[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];
            int xx = x * x;
            opUsed[i] = max(xx, max(opNotUsed[i - 1] + xx, opUsed[i - 1] + x));
            opNotUsed[i] = max(opNotUsed[i - 1] + x, x);
            ans = max(ans, opUsed[i]);
        }

        return ans;
    }

    // int maxSumAfterOperation(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     int opUsed = 0, opNotUsed = 0, ans = INT_MIN;

    //     for (int x: nums) {
    //         int xx = x * x;
    //         opUsed = max(xx, max(opNotUsed + xx, opUsed + x));
    //         opNotUsed = max(opNotUsed + x, x);
    //         ans = max(ans, opUsed);
    //     }

    //     return ans;
    // }
};