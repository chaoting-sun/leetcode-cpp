class Solution {
public:
    // Approach: DFS + memoization

    // int dfs(string &s, string &t, int i, int j, vector<vector<int>>& memo) {
    //     if (j == t.size()) {
    //         return 1;
    //     } else if (i == s.size()) {
    //         return 0;
    //     }

    //     if (memo[i][j] != -1) {
    //         return memo[i][j];
    //     }
    //     int cnt = 0;
    //     if (s[i] == t[j]) {
    //         cnt += dfs(s, t, i + 1, j, memo) + dfs(s, t, i + 1, j + 1, memo);
    //     } else {
    //         cnt += dfs(s, t, i + 1, j, memo);
    //     }
    //     memo[i][j] = cnt;
    //     return cnt;
    // }

    // int numDistinct(string s, string t) {
    //     int n1 = s.size();
    //     int n2 = t.size();
        
    //     if (n1 < n2) return 0;
    //     if (n1 == 0 || n2 == 0) return 0;

    //     vector<vector<int>> memo(n1, vector<int>(n2, -1));

    //     return dfs(s, t, 0, 0, memo);
    // }

    // Approach: DP
    // state: f(i, j) = number of subsequences of s[i:] that form t[j:]
    // transition:
    //      if s[i] == t[j]: f(i, j) = f(i+1, j) + f(i+1, j+1)
    //      else: f(i, j) = f(i+1, j)
    // base case:
    //      if j == |t|: return 1
    //      else if i == |s|: return 0

    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<unsigned int>> dp(n1 + 1, vector<unsigned int>(n2 + 1, 0));

        // base case
        for (int i = 0; i <= n1; i++) dp[i][n2] = 1;
        for (int j = 0; j < n2; j++) dp[n1][j] = 0;
        
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};