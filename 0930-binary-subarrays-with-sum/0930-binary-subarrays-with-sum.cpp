class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> prefixCount;
        prefixCount.reserve(n);
        prefixCount[0] = 1;

        int ans = 0;
        int prefix = 0;

        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            ans += prefixCount[prefix - goal];
            prefixCount[prefix]++;
        }
        return ans;
    }
};