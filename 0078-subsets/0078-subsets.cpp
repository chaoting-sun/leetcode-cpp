class Solution {
public:
    // Approach: backtracking (easiler to understand)

    // Time: O(n*2^n). there are totally 2^n subsets. adding a subset into the ans takes O(n), and I need to do
    // this copy for every subset. so the time = # subsets * cost per subset
    // Space: O(n). each backtrack function calls two backtrack functions with the size of nums to handle decreases by 1

    // vector<vector<int>> ans;

    // void backtrack(int idx, vector<int>& nums, vector<int> subset) {
    //     if (idx == nums.size()) {
    //         ans.push_back(subset);
    //         return;
    //     }

    //     int num = nums[idx];
    //     // not contain
    //     backtrack(idx + 1, nums, subset);
    //     // contain
    //     subset.push_back(num);
    //     backtrack(idx + 1, nums, subset);
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     backtrack(0, nums, vector<int>());
    //     return ans;
    // }

    // more adaptable

    vector<vector<int>> ans;

    void backtrack(int start_idx, vector<int>& nums, vector<int> subset) {
        // reach satisfied condition
        ans.push_back(subset);

        // iterate through the selection list
        for (int i = start_idx; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums, vector<int>());
        return ans;
    }
};