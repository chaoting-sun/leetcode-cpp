class Solution {
public:
    // Approach: we search for all possible solutions by recursively visiting the candidates
    // in order, and choosing to select or not select the current value in the subset. we
    // save a subset into the ans once the sum equals to target

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int credit, int idx, vector<int> subset) {
        // reach the termination condition
        if (credit == 0) {
            ans.push_back(subset);
            return;
        }
        if (idx >= candidates.size()) return;
        if (credit < candidates[idx]) return;

        // skip the current value
        backtrack(candidates, credit, idx + 1, subset);

        // select the current value
        subset.push_back(candidates[idx]);
        credit -= candidates[idx];
        backtrack(candidates, credit, idx, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, vector<int>());
        return ans;
    }
};