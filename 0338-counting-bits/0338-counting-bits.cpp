class Solution {
public:
    int count(int m) {
        int res = 0;
        while (m > 0) {
            res += m & 1;
            m = m >> 1;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(count(i));
        }
        return ans;
    }
};