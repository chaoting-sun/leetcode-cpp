class Solution {
private:
    bool isValid(const vector<int>& nums, int sum_constraint, int k) {
        int groups = 0;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int next_sum = current_sum + nums[i];
            if (next_sum > sum_constraint) {
                groups++;
                current_sum = nums[i];
                if (groups == k) return false;
            } else {
                current_sum = next_sum;
            }
        }
        groups++; // consider the last group
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
        
        int left = max_val;
        int right = total_sum;

        // find the first max subarrray sum that is possible
        while (left < right) {
            int sum_constraint = left + (right - left) / 2;
            if (isValid(nums, sum_constraint, k)) {
                right = sum_constraint;
            } else {
                left = sum_constraint + 1;
            }
        }
        return right;
    }
};