class Solution {
public:
    // Approach: backtracking
    // we handle case with duplicate value.
    // EX: [1,2,2,5]
    // we will consider [1,5], [1,2,5], [1,2,2,5] in the same level

    // vector<vector<int>> ans;

    // void backtrack(vector<int>& candidates, int remain, int start_idx, vector<int> subset) {
    //     if (remain < 0) return;
    //     if (remain == 0) {
    //         ans.push_back(subset);
    //         return;
    //     }

    //     if (start_idx >= candidates.size()) {
    //         return;
    //     }

    //     int i = start_idx;
    //     while (i < candidates.size()) {
    //         int left_idx = i, right_idx = i;
    //         while (right_idx + 1 < candidates.size() && candidates[left_idx] == candidates[right_idx + 1]) {
    //             right_idx++;
    //         }
            
    //         vector<int> new_subset = subset;
    //         int new_remain = remain;

    //         for (int j = left_idx; j <= right_idx; j++) {
    //             new_subset.push_back(candidates[j]);
    //             new_remain -= candidates[j];
    //             backtrack(candidates, new_remain, right_idx + 1, new_subset);
    //         }

    //         i = right_idx + 1;
    //     }
    // }

    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     backtrack(candidates, target, 0, vector<int>());
    //     return ans;
    // }

    // Simplified Version

    // Time: O(n*2^n). in worst case we exhaust all possible combinations from the input array.
    // in worst case, in which each number is unique, the number of combinations will be O(2^n).
    // also, it takes O(n) to copy the subset to the ans
    // Space: O(n)

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int remain, int start_idx, vector<int> subset) {
        if (remain < 0) return;
        if (remain == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = start_idx; i < candidates.size(); i++) {
            // pass the duplicate value to avoid subset duplication
            if (start_idx < i && candidates[i - 1] == candidates[i]) {
                continue;
            }
            // early termination if the current subset is impossible to be a valid combination
            if (remain < candidates[i]) {
                return;
            }
            subset.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, vector<int>());
        return ans;
    }
};