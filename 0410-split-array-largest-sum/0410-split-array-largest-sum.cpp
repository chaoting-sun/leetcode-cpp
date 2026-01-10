class Solution {
private:
    bool isValid(const vector<int>& nums, long long limit, int k) {
        int groups = 1;
        long long current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (current_sum + nums[i] > limit) {
                if (groups == k) return false;
                groups++;
                current_sum = nums[i];
            } else {
                current_sum += nums[i];
            }
        }
        return groups <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int length = nums.size();
        if (length < k) return -1;

        // find the upper bound and lower bound of the max subarray sum
        int total_sum = 0;
        int max_val = nums[0];
        for (int n: nums) {
            total_sum += n;
            max_val = max(max_val, n);
        }
        
        long long left = max_val;
        long long right = total_sum;

        // find the first max subarrray sum that is possible
        while (left < right) {
            long long limit = left + (right - left) / 2;
            if (isValid(nums, limit, k)) {
                right = limit;
            } else {
                left = limit + 1;
            }
        }
        return (int)right;
    }
};