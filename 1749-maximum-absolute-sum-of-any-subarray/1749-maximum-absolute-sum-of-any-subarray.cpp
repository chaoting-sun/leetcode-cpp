class Solution {
public:
    // int maxAbsoluteSum(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
        
    //     vector<int> minSum(n), maxSum(n);
    //     minSum[0] = maxSum[0] = nums[0];
    //     int ans = abs(nums[0]);

    //     for (int i = 1; i < n; i++) {
    //         minSum[i] = min(nums[i], minSum[i - 1] + nums[i]);
    //         maxSum[i] = max(nums[i], maxSum[i - 1] + nums[i]);
    //         ans = max(ans, max(abs(minSum[i]), abs(maxSum[i])));
    //     }

    //     return ans;
    // }

    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int minSum = nums[0], maxSum = nums[0];
        int ans = abs(nums[0]);

        for (int i = 1; i < n; i++) {
            minSum = min(nums[i], minSum + nums[i]);
            maxSum = max(nums[i], maxSum + nums[i]);
            ans = max(ans, max(abs(minSum), abs(maxSum)));
        }

        return ans;
    }
};