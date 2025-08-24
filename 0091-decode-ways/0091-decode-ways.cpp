class Solution {
public:
    // Approach: DP
    // def. of dp[i]: the number of decode ways from 0 to i of s
    // initialization: dp[0] = 0, dp[1] = if s[0] is valid
    // state transition function: dp[i] =
    //      dp[i - 1] if si is valid else 0
    //      +
    //      dp[i - 2] if s(i-1)~si is valid else 0

    // Time: O(n)
    // Space: O(n)

    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            int two_digits = stoi(s.substr(i - 2, 2));
            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    
        return dp[n];
    }
};