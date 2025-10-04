class Solution {
public:
    // Approach: BFS
    // The problem asks the shortest path from the original cell to any food cell, so we can come up with the
    // BFS method, in which we are able to explore the cell layer by layer. We use queue to store the position
    // to be handled, and maintain a variable step to track the current layer. Once a cell is visited, we mark
    // it as 'X' to avoid visiting again.

    // Time: O(mn)
    // Space: O(mn)

    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    int getFood(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        int step = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '*') {
                    q.push({ x, y });
                    grid[x][y] = 'X';
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            step++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 'X') {
                        if (grid[nx][ny] == '#') {
                            return step;
                        }
                        q.push({ nx, ny });
                        grid[nx][ny] = 'X';
                    }
                }
            }
        }

        return -1;
    }
};