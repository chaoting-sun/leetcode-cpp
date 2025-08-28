class Solution {
public:
    // Approach: DFS

    // vector<int> x_dirs = { 0, 0, 1, -1 };
    // vector<int> y_dirs = { 1, -1, 0, 0 };
    
    // int longestIncreasingPath(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if (m == 0 || n == 0) return 0;

    //     int max_step = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             max_step = max(max_step, dfs(matrix, i, j));
    //         }
    //     }

    //     return max_step;
    // }

    // int dfs(vector<vector<int>>& matrix, int i, int j) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     int max_step = 0;
    //     for (int d = 0; d < 4; d++) {
    //         int newi = i + x_dirs[d];
    //         int newj = j + y_dirs[d];
    //         if (newi >= 0 && newi < m && newj >= 0 && newj < n && matrix[newi][newj] > matrix[i][j]) {
    //             max_step = max(max_step, dfs(matrix, newi, newj));
    //         }
    //     }
    //     max_step++;

    //     return max_step;
    // }

    vector<int> x_dirs = { 0, 0, 1, -1 };
    vector<int> y_dirs = { 1, -1, 0, 0 };
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0) return 0;

        int max_step = 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max_step = max(max_step, dfs(matrix, i, j, memo));
            }
        }

        return max_step;
    }

    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo) {
        if (memo[i][j] != -1) return memo[i][j];
        
        int m = matrix.size();
        int n = matrix[0].size();

        int max_step = 0;
        for (int d = 0; d < 4; d++) {
            int newi = i + x_dirs[d];
            int newj = j + y_dirs[d];
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && matrix[newi][newj] > matrix[i][j]) {
                max_step = max(max_step, dfs(matrix, newi, newj, memo));
            }
        }
        max_step++;
        memo[i][j] = max_step;
        return max_step;
    }
};