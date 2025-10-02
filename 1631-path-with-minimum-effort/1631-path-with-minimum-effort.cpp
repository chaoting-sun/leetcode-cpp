using PI2 = pair<int,int>;

class Solution {
public:
    // dist[i'][j'] = max(abs(grid[i][j] - grid[i'][j']), dist[i][j]);

    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        if (m == 0 || n == 0) return -1;
        
        priority_queue<PI2, vector<PI2>, greater<>> pq;
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

        pq.push({ 0, 0 });
        distance[0][0] = 0;

        while (!pq.empty()) {
            auto [currentDistance, position] = pq.top();
            int x = position / n, y = position % n;
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return currentDistance;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int newDistance = max(abs(heights[x][y] - heights[nx][ny]), distance[x][y]);
                if (newDistance < distance[nx][ny]) {
                    distance[nx][ny] = newDistance;
                    pq.push({ distance[nx][ny], nx * n + ny });
                }
            }
        }

        return -1;
    }
};