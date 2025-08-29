class Solution {
public:
    // Approach: dfs
    // start from word1[i] and word2[j] where i = 0, j = 0, and try to do replace/delete/insert every time.

    int dfs(string word1, string word2, int i, int j, vector<vector<int>> &memo) {
        if (i == word1.size() && j == word2.size()) {
            return 0;
        } else if (i < word1.size() && j == word2.size()) {
            return word1.size() - i;
        } else if (i == word1.size() && j < word2.size()) {
            return word2.size() - j;
        }

        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i] == word2[j]) {
            memo[i][j] = dfs(word1, word2, i + 1, j + 1, memo);
        } else {
            // replace, delete, insert
            memo[i][j] = 1 + min(dfs(word1, word2, i + 1, j + 1, memo), min(dfs(word1, word2, i + 1, j, memo), dfs(word1, word2, i, j + 1, memo)));
        }
        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));

        return dfs(word1, word2, 0, 0, memo);
    }
};