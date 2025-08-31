// Approach: Backtracking

class Solution {
public:
    int best_diff = INT_MAX;
    vector<int> best_buckets;

    void updateBest(vector<int> &buckets) {
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int v: buckets) {
            min_val = min(min_val, v);
            max_val = max(max_val, v);
        }
        if (max_val - min_val < best_diff) {
            best_diff = max_val - min_val;
            best_buckets = buckets;
        }
    }

    void backtrack(int remaining, int k, int start, vector<int>& buckets) {
        // overpicked
        if (k < 0) return;
        
        // if product done, pad with 1s and evaluate
        if (remaining == 1) {
            if (k > 0) buckets.insert(buckets.end(), k, 1);
            updateBest(buckets);
            if (k > 0) buckets.erase(buckets.end() - k, buckets.end());
            return;
        }

        // no slots left but product unfinished
        if (k == 0) return;

        // select one
        for (int d = start; d <= remaining; d++) {
            if (remaining % d != 0) continue;
            buckets.push_back(d);
            backtrack(remaining / d, k - 1, d, buckets);
            buckets.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> buckets;
        best_buckets.resize(k);
        backtrack(n, k, 2, buckets);
        return best_buckets;
    }
};