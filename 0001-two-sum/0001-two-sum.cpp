class Solution {
public:
    // brute-force
    // time: O(n**2): nested loop of the vector of n elements
    // space: O(1)

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }
        return {};
    }

    // one-pass hash table
    // time: O(n) -> traverse the vector containing n elements only once. each lookup in the table cost only O(1) time.
    // space: O(n) -> use a map which stores at most n elements

    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> hash{};

    //     for (int i = 0; i < nums.size(); i++) {
    //         int complement = target - nums[i];
    //         if (hash.find(complement) != hash.end()) {
    //             return { hash[complement], i };
    //         }
    //         hash.insert({ nums[i], i });
    //     }
    //     return {};
    // }


};