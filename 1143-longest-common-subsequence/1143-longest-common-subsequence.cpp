class Solution {
public:
    // Approach: DP
    // dp[i+1][j+1]: the length of common substring for text1[0~i] and text2[0~j]
    // dp[i+1][j+1] =
    //  - text1[i] == text2[j] ? dp[i][j] + 1
    //  - text1[i] != text2[j] ? max(dp[i][j-1], dp[i-1][j])
    // Initialization: dp[0][0] = 0, dp[i][0] = 0, dp[0][j] = 0

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if (m == 0 || n == 0) return 0;
  
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[0][0] = 0;
        for (int i = 0; i <= m; i++) dp[i][0] = 0;
        for (int j = 0; j <= n; j++) dp[0][j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};

// abcde
// ace

//   # a c e
// # 0 0 0 0
// a 0 1 1 1
// b 0 1 1 1
// c 0 1 2 2
// d 0 1 2 2
// e 0 1 2 3 