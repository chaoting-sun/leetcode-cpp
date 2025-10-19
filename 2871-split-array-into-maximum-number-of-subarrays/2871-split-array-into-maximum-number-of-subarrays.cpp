class Solution {
public:
    // int maxSubarrays(vector<int>& nums) {
    //     int n = nums.size();
    //     int minScore = nums[0];
    //     for (int i = 1; i < n; i++) minScore &= nums[i];
    //     if (minScore > 0) return 1;

    //     int val = nums[0];
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         val &= nums[i];
    //         if (val == 0) {
    //             ans += 1;
    //             if (i < n - 1) val = nums[i + 1];
    //         }
    //     }
    //     return ans;
    // }

    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int minScore = nums[0];
        for (int i = 1; i < n; i++) minScore &= nums[i];
        if (minScore > 0) return 1;

        vector<int> dp(n);
        vector<int> last(20, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 20; j++) {
                if ((nums[i] & (1 << j)) == 0) last[j] = i;
            }

            int minZeroPosition = i;
            for (int j = 0; j < 20; j++) {
                minZeroPosition = min(minZeroPosition, last[j]);
            }

            if (minZeroPosition == -1) {
                dp[i] = -1;
            } else if (minZeroPosition == 0 || dp[minZeroPosition - 1] == -1) {
                dp[i] = 1;
            } else {
                dp[i] = dp[minZeroPosition - 1] + 1;
            }
        }
        return dp[n - 1];
    }
};