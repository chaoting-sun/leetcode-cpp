class Solution {
public:
    // Approach1: Sliding Window
    // Time: O(n)
    // Space: O(1)

    // int longestOnes(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
        
    //     int start = 0, end = 0;
    //     int maxLength = 0;
    //     int numZeros = 0;
        
    //     while (end < n) {
    //         if (nums[end] == 0) numZeros++;
    //         // shrink the window from start if it is invalid
    //         while (numZeros > k) {
    //             if (nums[start] == 0) numZeros--;
    //             start++;
    //         }
    //         maxLength = max(maxLength, end - start + 1);
    //         end++;
    //     }
    //     return maxLength;
    // }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int zeroCnt = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroCnt++;

            while (zeroCnt > k && left <= right) {
                if (nums[left] == 0) zeroCnt--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
