class Solution {
public:
    // Approach1

    // vector<vector<int>> ans;

    // void backtrack(vector<int>& nums, int idx, vector<int> subset) {
    //     ans.push_back(subset);

    //     for (int i = idx; i < nums.size(); i++) {
    //         if (i > idx && nums[i] == nums[i - 1]) continue;
    //         subset.push_back(nums[i]);
    //         backtrack(nums, i + 1, subset);
    //         subset.pop_back();
    //     }
    // }

    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     backtrack(nums, 0, vector<int>());
    //     return ans;
    // }

    // Approach2
    // Time: O(n*2^n). there are at most 2^n subset with each at most with n length.
    // Space: O(n*2^n)

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int idx, vector<int> subset) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // consider nums[idx]
        subset.push_back(nums[idx]);
        backtrack(nums, idx + 1, subset);

        subset.pop_back();

        // not consider nums[idx];
        // ignore all that is equal to nums[idx] to avoid duplicated subset
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        backtrack(nums, idx + 1, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, vector<int>());
        return ans;
    }
};
