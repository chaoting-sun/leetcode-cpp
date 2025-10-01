class Solution {
public:
    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return 0;

        // minSteps[i][j][k]: the min steps to arrive (i,j) after passing k obstacles
        vector<vector<vector<int>>> minSteps(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        queue<array<int,3>> q; // obstacles, x, y

        q.push({ 0, 0, 0 });
        minSteps[0][0][0] = 0;

        while (!q.empty()) {
            auto [obstacles, x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int newObstacles = obstacles + grid[nx][ny];
                if (newObstacles > k || minSteps[nx][ny][newObstacles] != INT_MAX) continue;
                minSteps[nx][ny][newObstacles] = minSteps[x][y][obstacles] + 1;
                q.push({ newObstacles, nx, ny });
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= k; i++) ans = min(ans, minSteps[m-1][n-1][i]);
        return ans == INT_MAX ? -1 : ans;
    }
};