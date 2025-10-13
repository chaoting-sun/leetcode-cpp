class Solution {
public:
    // int longestSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n <= 2) return n;

    //     int maxLength = 2;
    //     int l = 0, r = 1;
    //     while (r < n - 1) {
    //         if (nums[r - 1] + nums[r] == nums[r + 1]) {
    //             r++;
    //             maxLength = max(maxLength, r - l + 1);
    //         } else {
    //             l = r;
    //             r++;
    //         }
    //     }
    //     return maxLength;
    // }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int maxLength = 2, currLength = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i - 2] + nums[i - 1] == nums[i]) {
                currLength++;
            } else {
                currLength = 2;
            }
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};