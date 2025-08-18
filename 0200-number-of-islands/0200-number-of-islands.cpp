class Solution {
public:
    // Approach: DFS
    // Time: (m*n)
    // Space: O(m*n)

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

    // Approach: DFS (inplace change)
    // Time: (m*n)
    // Space: O(m*n)

    // void findIsland(vector<vector<char>>& grid, int i, int j) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     if (i < 0 || i >= m || j < 0 || j >= n) return;
    //     if (grid[i][j] != '1') return;

    //     grid[i][j] = '0';

    //     findIsland(grid, i + 1, j);
    //     findIsland(grid, i - 1, j);
    //     findIsland(grid, i, j + 1);
    //     findIsland(grid, i, j - 1);
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
        
    //     int count = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == '1') {
    //                 findIsland(grid, i, j);
    //                 count++;
    //             }
    //         }
    //     }

    //     return count;
    // }

    // BFS
    // Time: O(n*m)
    // Space: O(min(n,m))

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') continue;

                count++;

                queue<pair<int,int>> q_cell;
                q_cell.push({ i, j });

                while (!q_cell.empty()) {
                    int size = q_cell.size();
                    for (int k = 0; k < size; k++) {
                        int curr_i = q_cell.front().first;
                        int curr_j = q_cell.front().second;
                        q_cell.pop();

                        if (curr_i > 0 && grid[curr_i - 1][curr_j] == '1') {
                            q_cell.push({ curr_i - 1, curr_j });
                            grid[curr_i - 1][curr_j] = '#';
                        }
                        if (curr_i < m - 1 && grid[curr_i + 1][curr_j] == '1') {
                            q_cell.push({ curr_i + 1, curr_j });
                            grid[curr_i + 1][curr_j] = '#';
                        }
                        if (curr_j > 0 && grid[curr_i][curr_j - 1] == '1') {
                            q_cell.push({ curr_i, curr_j - 1 });
                            grid[curr_i][curr_j - 1] = '#';
                        }
                        if (curr_j < n - 1 && grid[curr_i][curr_j + 1] == '1') {
                            q_cell.push({ curr_i, curr_j + 1 });
                            grid[curr_i][curr_j + 1] = '#';
                        }
                    }
                }
            }
        }

        return count;
    }
};

