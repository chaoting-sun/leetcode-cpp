class Solution {
public:
    // Two Pointers
    // Time: O(n^2)
    // Space: O(1)

    int countInSubstring(string& s, int l, int r) {
        if (s[l] != s[r]) return 0;
        int n = s.size();
        int count = 1;

        while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
            l--;
            r++;
            count++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += countInSubstring(s, i, i);
        }
        for (int i = 0; i < n - 1; i++) {
            ans += countInSubstring(s, i, i + 1);
        }
        return ans;
    }
};