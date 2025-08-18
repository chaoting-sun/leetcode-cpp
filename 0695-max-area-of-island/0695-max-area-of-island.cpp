class Solution {
public:
    // Approach: DFS in recursive style
    // Time: O(m*n)
    // Space: O(m*n)

    // void dfsCountArea(vector<vector<int>>& grid, int i, int j, int& count) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     if (i < 0 || i > m - 1 || j < 0 || j > n - 1) return;
    //     if (grid[i][j] != 1) return;

    //     count++;
    //     grid[i][j] = 2;

    //     dfsCountArea(grid, i - 1, j, count);
    //     dfsCountArea(grid, i + 1, j, count);
    //     dfsCountArea(grid, i, j - 1, count);
    //     dfsCountArea(grid, i, j + 1, count);
    // }

    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int max_count = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 1) {
    //                 int count = 0;
    //                 dfsCountArea(grid, i, j, count);
    //                 max_count = max(max_count, count);
    //             }
    //         }
    //     }

    //     return max_count;
    // }


    // Another Style of DFS in recursive style

    // int dfsCountArea(vector<vector<int>>& grid, int i, int j) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     if (i < 0 || i >= m || j < 0 || j >= n) return 0;
    //     if (grid[i][j] != 1) return 0;

    //     grid[i][j] = 2;

    //     return 1 + dfsCountArea(grid, i - 1, j)
    //              + dfsCountArea(grid, i + 1, j)
    //              + dfsCountArea(grid, i, j - 1)
    //              + dfsCountArea(grid, i, j + 1);
    // }

    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int max_count = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 1) {
    //                 int count = dfsCountArea(grid, i, j);
    //                 max_count = max(max_count, count);
    //                 cout << count << " ";
    //             }
    //         }
    //     }

    //     return max_count;
    // }

    // DFS in iterative style

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1 || visited[i][j]) continue;

                stack<pair<int, int>> stk;
                stk.push({i, j});
                int count = 0;

                while (!stk.empty()) {
                    int ci = stk.top().first;
                    int cj = stk.top().second;
                    stk.pop();

                    count++;
                    visited[ci][cj] = true;

                    if (ci > 0 && grid[ci - 1][cj] == 1 && !visited[ci - 1][cj]) stk.push({ ci - 1, cj });
                    if (ci < m - 1 && grid[ci + 1][cj] == 1 && !visited[ci + 1][cj]) stk.push({ ci + 1, cj });
                    if (cj > 0 && grid[ci][cj - 1] == 1 && !visited[ci][cj - 1]) stk.push({ ci, cj - 1 });
                    if (cj < n - 1 && grid[ci][cj + 1] == 1 && !visited[ci][cj + 1]) stk.push({ ci, cj + 1 });
                }

                max_count = max(max_count, count);
            }
        }

        return max_count;
    }
};