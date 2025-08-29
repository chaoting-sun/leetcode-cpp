class Solution {
public:
    int dfs(string &s, string &t, int i, int j, vector<vector<int>>& memo) {
        if (j == t.size()) {
            return 1;
        } else if (i == s.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int cnt = 0;
        if (s[i] == t[j]) {
            cnt += dfs(s, t, i + 1, j, memo) + dfs(s, t, i + 1, j + 1, memo);
        } else {
            cnt += dfs(s, t, i + 1, j, memo);
        }
        memo[i][j] = cnt;
        return cnt;
    }

    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        if (n1 < n2) return 0;
        if (n1 == 0 || n2 == 0) return 0;

        vector<vector<int>> memo(n1, vector<int>(n2, -1));

        return dfs(s, t, 0, 0, memo);
    }
};