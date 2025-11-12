class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixCount(n);
        int ans = 0;
        int prefix = 0;
        prefixCount[prefix] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            ans += prefixCount[prefix - k];
            prefixCount[prefix]++;
        }
        return ans;
    }
};
