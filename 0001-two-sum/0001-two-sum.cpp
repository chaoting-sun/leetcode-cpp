class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> needed; // needed value: previous index
        for (int i = 0; i < nums.size(); i++) {
            if (needed.count(nums[i])) {
                return { i, needed[nums[i]] };
            }
            needed[target - nums[i]] = i;
        }
        return {};     
    }
};