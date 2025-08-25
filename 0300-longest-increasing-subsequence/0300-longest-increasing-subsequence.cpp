class Solution {
public:
    // Approach: DP
    // dp[i]: the number of strictly increasing subsequence end at i
    // dp[i] = max(dp[0] + 1 if nums[i] > nums[0], ..., dp[i-1] + 1 if nums[i] > nums[i-1], dp[i])

    // Time: O(n^2)
    // Space: O(n)

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     vector<int> dp(n, 1);
    //     int max_length = 1;

    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //         max_length = max(max_length, dp[i]);
    //     };

    //     return max_length;
    // }

    // Approach: Greedy + Binary Search
    // Time: O(n*logn)
    // Space: O(n)

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> subarr;
        subarr.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > subarr.back()) {
                subarr.push_back(nums[i]);
            } else {
                // find the first digit that is equal or larger than nums[i]
                // define True condition: subarr[mid] >= nums[i]
                int left = 0; // FF(.)..
                int right = subarr.size(); // ..(T)TT
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (subarr[mid] >= nums[i]) { // T
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                subarr[left] = nums[i];
            }
        }

        return subarr.size();
    }
};