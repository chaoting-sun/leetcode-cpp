class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return -1;

        queue<pair<int,int>> q;
        int step = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '*') {
                    q.push({ x, y });
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            step++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
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