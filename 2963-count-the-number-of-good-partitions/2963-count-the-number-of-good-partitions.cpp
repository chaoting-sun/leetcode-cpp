class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        unordered_map<int, pair<int,int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            if (!pairs.count(nums[i])) {
                pairs[nums[i]] = { i, i };
            } else {
                pairs[nums[i]].second = i;
            }
        }
        
        int ans = 1;
        int maxR = pairs[nums[0]].second;
        for (int i = 1; i < nums.size(); i++) {
            if (i <= maxR) {
                maxR = max(maxR, pairs[nums[i]].second);
            } else {
                maxR = pairs[nums[i]].second;
                ans = (ans * 2) % MOD;
            }
        }
        return ans;
    }
};