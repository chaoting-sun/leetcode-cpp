class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int start = 0, end = 0;
        int maxLength = 0;
        int numZeros = 0;
        
        while (end < n) {
            if (nums[end] == 0) numZeros++;
            // shrink the window from start if it is invalid
            while (numZeros > k) {
                if (nums[start] == 0) numZeros--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        return maxLength;
    }
};

// class Solution {
// public:
//     // Approach1: Sliding Window
//     // Time: O(n)
//     // Space: O(1)

//     int longestOnes(vector<int>& nums, int k) {
//         int left = 0, right = 0;
//         int max_cnt = 0;
//         int n = nums.size();
//         int one_cnt = 0; // number of 1s

//         while (right < n) {
//             // count the number of 1s
//             if (nums[right] == 1) one_cnt++;
            
//             // ensure that the number of 0s is not larger then k
//             while ((right - left + 1) - one_cnt > k) {
//                 if (nums[left] == 1) one_cnt--;
//                 left++;
//             }
            
//             max_cnt = max(max_cnt, right - left + 1);
            
//             right++;
//         }

//         return max_cnt;
//     }
// };