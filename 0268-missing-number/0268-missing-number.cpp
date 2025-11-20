class Solution {
public:
    // Bit Manipulation
    // Time: O(n)
    // Space: O(1)

    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = 0;
    //     for (int i = 1; i <= n; i++) res ^= i;
    //     for (int v: nums) res ^= v;
    //     return res;
    // }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) return i;
        }
        return n;
    }
};