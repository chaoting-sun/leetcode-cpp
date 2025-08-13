class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int idx, vector<int>& nums, vector<int> subset) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        int num = nums[idx];
        // not contain
        backtrack(idx + 1, nums, subset);
        // contain
        subset.push_back(num);
        backtrack(idx + 1, nums, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums, vector<int>());
        return ans;
    }
};