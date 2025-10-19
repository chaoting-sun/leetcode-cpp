class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int minScore = nums[0];
        for (int i = 1; i < n; i++) minScore &= nums[i];
        if (minScore > 0) return 1;

        int val = nums[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            val &= nums[i];
            if (val == 0) {
                ans += 1;
                if (i < n - 1) val = nums[i + 1];
            }
        }
        return ans;
    }
};