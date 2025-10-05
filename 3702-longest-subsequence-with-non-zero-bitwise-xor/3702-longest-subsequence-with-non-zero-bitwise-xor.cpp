class Solution {
public:
    // Approach: Bit Manipulation
    // Time: O(n)
    // Space: O(1)

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];
        bool hasNoneZero = false;
        for (int i = 1; i < n; i++) {
            s ^= nums[i];
            if (nums[i] != 0) hasNoneZero = true;
        }
        if (s != 0) {
            return n;
        } else {
            return hasNoneZero ? n - 1 : 0;
        }
    }
};

    