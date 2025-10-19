class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> numbers;
        for (int i = 1; i <= k; i++) numbers.insert(i);
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            numbers.erase(nums[i]);
            if (numbers.empty()) {
                return n - i;
            }
        }
        return -1;
    }
};