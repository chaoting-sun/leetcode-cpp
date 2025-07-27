class Solution {
public:
    // one-pass hash table
    // time: O(n) -> traverse the vector containing n elements only once. each lookup in the table cost only O(1) time.
    // space: O(n) -> use a map which stores at most n elements
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash{};

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return { hash[complement], i };
            }
            hash.insert({ nums[i], i });
        }
        return {};
    }
};