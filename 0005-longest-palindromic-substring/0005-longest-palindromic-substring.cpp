class Solution {
public:
    // Approach: 2D DP
    // meaning of dp[i][j]: if the substring [i,j] in s is a palindromic substring
    // initialization: set dp[i][i] to true
    // state transition function dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]

    // Time: O(n^2)
    // Space: O(n^2)

    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     int lmax = 0, rmax = 0;

    //     for (int i = 0; i < n; i++) dp[i][i] = true;

    //     for (int l = n - 1; l >= 0; l--) {
    //         for (int r = l + 1; r < n; r++) {
    //             if (l + 1 == r) {
    //                 dp[l][r] = s[l] == s[r];
    //             } else {
    //                 dp[l][r] = dp[l + 1][r - 1] && s[l] == s[r];
    //             }
    //             if (dp[l][r] && r - l > rmax - lmax) {
    //                 lmax = l;
    //                 rmax = r;
    //             }
    //         }
    //     }

    //     return s.substr(lmax, rmax - lmax + 1);
    // }

    // Approach: Two Pointers
    // Time: O(n)
    // Space: O(1)

    pair<int, int> findMaxPalindrome(string& s, int l, int r) {
        if (s[l] != s[r]) return { -1, -1 };

        int n = s.size();
        while (0 < l && r < n - 1 && s[l - 1] == s[r + 1]) {
            l--;
            r++;
        }
        return { l, r };
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int lmax = 0, rmax = 0;

        // odd
        for (int i = 0; i < n; i++) {
            auto [l, r] = findMaxPalindrome(s, i, i);
            if (r - l > rmax - lmax) {
                rmax = r;
                lmax = l;
            }
        }

        // even
        for (int i = 0; i < n - 1; i++) {
            auto [l, r] = findMaxPalindrome(s, i, i + 1);
            if (r - l > rmax - lmax) {
                rmax = r;
                lmax = l;
            }
        }

        return s.substr(lmax, rmax - lmax + 1);
    }
};