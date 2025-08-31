class Solution {
public:
    int min_diff = INT_MAX;
    vector<int> best_buckets;

    void updateBest(vector<int> &buckets) {
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int v: buckets) {
            min_val = min(min_val, v);
            max_val = max(max_val, v);
        }
        if (max_val - min_val < min_diff) {
            min_diff = max_val - min_val;
            best_buckets = buckets;
        }
    }

    void backtrack(int remaining, int k, int start, vector<int>& buckets) {
        if (k < 0) {
            // invalid
            return;
        } else {
            // termination condition
            if (remaining == 1) {
                if (k > 0) for (int i = 0; i < k; i++) buckets.push_back(1);
                updateBest(buckets);
                for (int i = 0; i < k; i++) buckets.pop_back();
                return;
            }
        }

        // select one
        for (int div = start; div <= remaining; div++) {
            if (remaining % div == 0) {
                buckets.push_back(div);
                backtrack(remaining / div, k - 1, div, buckets);
                buckets.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> buckets;
        best_buckets.resize(k);
        backtrack(n, k, 2, buckets);
        return best_buckets;
    }
};