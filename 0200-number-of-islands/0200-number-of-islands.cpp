class Solution {
public:
    // Approach: DFS

    // int m;
    // int n;

    // bool findIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    //     if (i < 0 || i >= m || j < 0 || j >= n) return false;
    //     if (visited[i][j]) return false;
    //     if (grid[i][j] == '0') return false;

    //     visited[i][j] = true;

    //     findIsland(grid, visited, i + 1, j);
    //     findIsland(grid, visited, i - 1, j);
    //     findIsland(grid, visited, i, j + 1);
    //     findIsland(grid, visited, i, j - 1);

    //     return true;
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     m = grid.size();
    //     n = grid[0].size();
        
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
    //     int count = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (!visited[i][j] && grid[i][j] == '1') {
    //                 bool found = findIsland(grid, visited, i, j);
    //                 if (found) count++;
    //             }
    //         }
    //     }

    //     return count;
    // }

    // Approach: DFS (inplace chang)

    void findIsland(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] != '1') return;

        grid[i][j] = '0';

        findIsland(grid, i + 1, j);
        findIsland(grid, i - 1, j);
        findIsland(grid, i, j + 1);
        findIsland(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    findIsland(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

