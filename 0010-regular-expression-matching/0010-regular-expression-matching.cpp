class Solution {
public:
    int dfs(string &s, string &p, int i, int j, vector<vector<int>> &memo) {
        cout << i << " " << j << "\n";

        if (memo[i][j] != -1) return memo[i][j];

        int n1 = s.size();
        int n2 = p.size();

        if (i >= n1 && j >= n2) {
            return 1; // valid
        } else if (j >= n2) {
            return 0; // invalid
        }

        int match = i < n1 && (s[i] == p[j] || p[j] == '.');

        if (j < n2 - 1 && p[j + 1] == '*') {
            memo[i][j] = dfs(s, p, i, j+2, memo) || (match && dfs(s, p, i+1, j, memo));
        } else {
            if (match) {
                memo[i][j] = dfs(s, p, i+1, j+1, memo);
            } else {
                memo[i][j] = 0;
            }
        }
        return memo[i][j];
    }  

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1)); // 0 -> invalid, 1 -> valid
        return dfs(s, p, 0, 0, memo) == 1 ? true : false;
    }
};
