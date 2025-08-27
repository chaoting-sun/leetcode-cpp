class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) return false;

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n1; i++) {
            dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
        }
        for (int j = 0; j < n2; j++) {
            dp[0][j + 1] = dp[0][j] && s2[j] == s3[j];
        }

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1[i] == s3[i + j + 1] && s2[j] == s3[i + j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                } else if (s1[i] == s3[i + j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else if (s2[j] == s3[i + j + 1]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                } else {
                    dp[i + 1][j + 1] = false;
                }
            }
        }

        return dp[n1][n2];
    }
};