class Solution {
public:
    // Approach: DFS
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


    // Another Style of DFS

    int dfsCountArea(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (grid[i][j] != 1) return 0;

        grid[i][j] = 2;

        return 1 + dfsCountArea(grid, i - 1, j)
                 + dfsCountArea(grid, i + 1, j)
                 + dfsCountArea(grid, i, j - 1)
                 + dfsCountArea(grid, i, j + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = dfsCountArea(grid, i, j);
                    max_count = max(max_count, count);
                    cout << count << " ";
                }
            }
        }

        return max_count;
    }
};