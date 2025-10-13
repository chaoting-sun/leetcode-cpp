class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                if ((i == m - 1 || grid[i + 1][j] == 0) &&
                    ( j == n - 1 || grid[i][j + 1] == 0)) {
                    grid[i][j] = 0;
                }
            }
        }
        if (grid[0][0] == 0) return true;
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for (int i = 0; i < m + n - 3; i++) {
            if (x1 < m - 1 && grid[x1 + 1][y1] == 1) x1++;
            else y1++;
            if (y2 < n - 1 && grid[x2][y2 + 1] == 1) y2++;
            else x2++;
            if (x1 == x2 && y1 == y2) return true;
        }
        return false;
    }
};
