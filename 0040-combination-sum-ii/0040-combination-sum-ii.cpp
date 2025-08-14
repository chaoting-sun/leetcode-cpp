class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int remain, int start_idx, vector<int> subset) {
        if (remain < 0) return;
        if (remain == 0) {
            ans.push_back(subset);
            return;
        }

        if (start_idx >= candidates.size()) {
            return;
        }

        int i = start_idx;
        while (i < candidates.size()) {
            int left_idx = i, right_idx = i;
            while (right_idx + 1 < candidates.size() && candidates[left_idx] == candidates[right_idx + 1]) {
                right_idx++;
            }
            
            vector<int> new_subset = subset;
            int new_remain = remain;

            for (int j = left_idx; j <= right_idx; j++) {
                new_subset.push_back(candidates[j]);
                new_remain -= candidates[j];
                backtrack(candidates, new_remain, right_idx + 1, new_subset);
            }

            i = right_idx + 1;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, vector<int>());
        return ans;
    }
};