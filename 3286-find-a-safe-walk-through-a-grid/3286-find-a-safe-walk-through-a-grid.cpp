class Solution {
public:
    vector<int> dx = { 0, 0, -1, 1 };
    vector<int> dy = { -1, 1, 0, 0 };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return false;
        
        queue<array<int,3>> q; // x, y, remaining health
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(health+1, false)));

        q.push({ 0, 0, health - grid[0][0] });
        visited[0][0][health] = true;

        while (!q.empty()) {
            auto [x, y, remainingHealth] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newRemainingHealth = remainingHealth - grid[nx][ny];
                    if (newRemainingHealth <= 0 || visited[nx][ny][newRemainingHealth]) continue;
                    visited[nx][ny][newRemainingHealth] = true;
                    q.push({ nx, ny, newRemainingHealth });
                }
            }
        }

        return false;
    }
};