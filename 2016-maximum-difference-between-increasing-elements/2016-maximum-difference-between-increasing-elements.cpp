class Solution {
public:
    // Time: O(n)
    // Space: O(1)

    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int max_diff = INT_MIN;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > min_val) max_diff = max(max_diff, nums[i] - min_val);
            min_val = min(min_val, nums[i]);
        }

        return max_diff == INT_MIN ? -1 : max_diff;
    }
};