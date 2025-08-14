
class Solution {
public:
    // Approach: we search for all possible solutions by recursively visiting the candidates
    // in order, and choosing to select or not select the current value in the subset. we
    // save a subset into the ans once the sum equals to target

    // Time: O(N^(T/M + 1)), T is target and M is the smallest value in candidates
    // as every value can be selected for unlimited times, the recursion depth will be T/M.
    // any time we have N options to select from, so there are at most O(N^(T/M)) options.
    // each subset is at most T/M elements, which cost T/M time to copy to the ans.
    // so the time is O(T/M * N^(T/M)) = O(N^(T/M + 1))
    // Space: O(T/M)

    // vector<vector<int>> ans;

    // void backtrack(vector<int>& candidates, int remain, int idx, vector<int> subset) {
    //     // reach the termination condition
    //     if (remain == 0) {
    //         ans.push_back(subset);
    //         return;
    //     }
    //     if (idx >= candidates.size()) return;
    //     if (remain < candidates[idx]) return;

    //     // skip the current value
    //     backtrack(candidates, remain, idx + 1, subset);

    //     // select the current value
    //     subset.push_back(candidates[idx]);
    //     remain -= candidates[idx];
    //     backtrack(candidates, remain, idx, subset);
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     backtrack(candidates, target, 0, vector<int>());
    //     return ans;
    // }

    // General approach

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int remain, int idx, vector<int> subset) {
        // reach the termination condition
        if (remain == 0) {
            ans.push_back(subset);
            return;
        } else if (remain < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // select the same element
            subset.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, vector<int>());
        return ans;
    }
};