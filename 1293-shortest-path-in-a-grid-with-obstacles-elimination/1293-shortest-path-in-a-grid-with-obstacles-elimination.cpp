class Solution {
public:
    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return 0;

        // visited[i][j][k]: the min steps to arrive (i,j) after passing k obstacles
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<array<int,3>> q; // obstacles, x, y

        q.push({ 0, 0, 0 });
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [obstacles, x, y] = q.front();
                q.pop();

                if (x == m - 1 && y == n - 1) {
                    return steps;
                }

                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    
                    int newObstacles = obstacles + grid[nx][ny];
                    if (newObstacles > k || visited[nx][ny][newObstacles]) continue;
                    visited[nx][ny][newObstacles] = true;

                    q.push({ newObstacles, nx, ny });
                }
            }

            steps++;
        }

        return -1;
    }
};