class Solution {
private:
    vector<int> accumulated_k;
    mt19937 engine;

public:
    Solution(vector<int>& w) {
        accumulated_k.resize(w.size());
        accumulated_k[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            accumulated_k[i] = accumulated_k[i - 1] + w[i];
        }

        random_device rd;
        engine.seed(rd());
    }
    
    int pickIndex() {
        int rd = getRandom();
        int l = 0, r = accumulated_k.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (accumulated_k[mid] >= rd) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    int getRandom() {
        uniform_int_distribution<int> distribution(1, accumulated_k.back());
        return distribution(engine);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */