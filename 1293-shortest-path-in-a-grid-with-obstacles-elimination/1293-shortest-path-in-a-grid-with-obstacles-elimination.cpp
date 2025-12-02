class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dx = { 1, -1, 0, 0 };
        vector<int> dy = { 0, 0, 1, -1 };
        
        vector<vector<vector<int>>> minDistance(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        queue<pair<int,int>> q; // distance, current obstacles
        q.push({ 0, 0 });
        minDistance[0][0][0] = 0;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [p, obstacles] = q.front();
                q.pop();
                int x = p / n;
                int y = p % n;

                if (x == m - 1 && y == n - 1) return steps;

                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                    
                    int newObstacles = obstacles + (grid[newX][newY] == 1 ? 1 : 0);
                    
                    if (newObstacles > k) continue; // invalid move
                    if (minDistance[newX][newY][newObstacles] != INT_MAX) continue; // visited

                    minDistance[newX][newY][newObstacles] = minDistance[x][y][obstacles] + 1;
                    q.push({ newX * n + newY, newObstacles });
                }
            }
            steps++;
        }
        return -1;
    }
};