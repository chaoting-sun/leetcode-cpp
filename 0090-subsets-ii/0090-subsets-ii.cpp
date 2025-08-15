class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int idx, vector<int> subset) {
        ans.push_back(subset);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, vector<int>());
        return ans;
    }
};
