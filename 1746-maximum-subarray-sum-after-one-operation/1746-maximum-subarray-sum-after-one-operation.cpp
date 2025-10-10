class Solution {
public:
    // int maxSumAfterOperation(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 0) return 0;

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

    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int opUsed = nums[0] * nums[0];
        int opNotUsed = nums[0];
        int ans = opUsed;

        for (int i = 1; i < n; i++) {
            int numSquared = nums[i] * nums[i];
            opUsed = max(numSquared, max(opNotUsed + numSquared, opUsed + nums[i]));
            opNotUsed = max(opNotUsed + nums[i], nums[i]);
            ans = max(ans, opUsed);
        }

        return ans;
    }
};