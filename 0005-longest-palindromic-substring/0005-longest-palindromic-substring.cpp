class Solution {
public:
    // Approach: DP
    // meaning of dp[i][j]: if the substring [i,j] in s is a palindromic substring
    // initialization: set dp[i][i] to true
    // state transition function dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]

    // Time: O(n^2)
    // Space: O(n^2)

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int lmax = 0, rmax = 0;

        for (int i = 0; i < n; i++) dp[i][i] = true;

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                if (l + 1 == r) {
                    dp[l][r] = s[l] == s[r];
                } else {
                    dp[l][r] = dp[l + 1][r - 1] && s[l] == s[r];
                }
                if (dp[l][r] && r - l > rmax - lmax) {
                    lmax = l;
                    rmax = r;
                }
            }
        }

        return s.substr(lmax, rmax - lmax + 1);
    }
};