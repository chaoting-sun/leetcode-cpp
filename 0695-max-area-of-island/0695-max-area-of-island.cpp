class Solution {
private:
    int dfsLand(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;

        int current_area = 1; // itself
        current_area += dfsLand(grid, i - 1, j);
        current_area += dfsLand(grid, i + 1, j);
        current_area += dfsLand(grid, i, j - 1);
        current_area += dfsLand(grid, i, j + 1);
        return current_area;
    };

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int max_area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int current_area = dfsLand(grid, i, j);
                    max_area = max(max_area, current_area);
                }
            }
        }
        return max_area;
    }
};

// Submit Error
// No ';' after dfsLand()
// No return in dfsLand()