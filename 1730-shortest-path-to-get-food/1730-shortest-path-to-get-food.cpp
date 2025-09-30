class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return -1;

        int x = -1, y = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    x = i;
                    y = j;
                }
            }
        }

        queue<pair<int,int>> q; // step, position
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({ 0, x * n + y });
        visited[x][y] = true;
        
        while (!q.empty()) {
            auto [step, position] = q.front();
            int cx = position / n, cy = position % n;
            q.pop();

            if (grid[cx][cy] == '#') {
                return step;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 'X' && !visited[nx][ny]) {
                    q.push({ step + 1, nx * n + ny });
                    visited[nx][ny] = true;
                }
            }
        }

        return -1;
    }
};