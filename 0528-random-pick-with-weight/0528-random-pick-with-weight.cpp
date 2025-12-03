class Solution {
private:
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        float rd = getRandom();
        int l = 0, r = prefix.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (prefix[mid] >= rd) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    float getRandom() {
        float randNum = (float)rand() / RAND_MAX;
        return randNum * prefix.back();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */