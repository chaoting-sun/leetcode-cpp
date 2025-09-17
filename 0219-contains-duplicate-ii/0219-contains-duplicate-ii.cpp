class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> existed;
        int n = nums.size();
        for (int i = 0; i < min(k + 1, n); i++) {
            if (existed.count(nums[i])) return true;
            existed.insert(nums[i]);
        }

        for (int i = k + 1; i < n; i++) {
            existed.erase(nums[i - k - 1]);
            if (existed.count(nums[i])) return true;
            existed.insert(nums[i]);
        }

        return false;
    }
};