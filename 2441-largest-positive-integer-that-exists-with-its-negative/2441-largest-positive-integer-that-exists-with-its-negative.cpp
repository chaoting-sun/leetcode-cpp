class Solution {
public:
    // Approach: Hash Map
    // Time: O(n)
    // Space: O(n)

    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> value_index; // value: index
        int max_value = INT_MIN;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (value_index.count(-nums[i])) {
                max_value = max(max_value, abs(nums[i]));
            }
            value_index[nums[i]] = i;
        }

        return max_value == INT_MIN ? -1 : max_value;
    }
};
