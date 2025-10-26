class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for (int k = 1; k <= n; k++) {
            string rev = s;
            reverse(rev.begin(), rev.begin() + k);
            if (rev < ans) ans = rev;
        }
        for (int k = 1; k <= n; k++) {
            string rev = s;
            reverse(rev.end() - k, rev.end());
            if (rev < ans) ans = rev;
        }
        return ans;
    }
};
