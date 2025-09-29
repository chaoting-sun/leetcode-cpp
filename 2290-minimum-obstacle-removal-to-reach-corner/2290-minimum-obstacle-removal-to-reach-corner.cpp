using PI2 = pair<int,int>;

class Solution {
public:
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = {  0, 0, 1, -1 };

    // int minimumObstacles(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     if (m == 0 || n == 0) return 0;
        
    //     priority_queue<PI2, vector<PI2>, greater<>> pq;
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));

    //     pq.push({ 0, 0 });
    //     visited[0][0] = 0;

    //     while (!pq.empty()) {
    //         auto [removed, position] = pq.top();
    //         pq.pop();
    //         int x = position / n, y = position % n;

    //         if (x == m - 1 && y == n - 1) return removed;

    //         for (int i = 0; i < 4; i++) {
    //             int nextX = x + dx[i];
    //             int nextY = y + dy[i];
    //             int nextPosition = nextX * n + nextY;

    //             if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !visited[nextX][nextY]) {
    //                 visited[nextX][nextY] = true;
    //                 if (grid[nextX][nextY] == 1) {
    //                     pq.push({ removed + 1, nextPosition });
    //                 } else {
    //                     pq.push({ removed, nextPosition });
    //                 }
    //             }
    //         }
    //     }

    //     return -1;
    // }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq; // x, y
        dq.push_back({ 0, 0 });
        minObstacles[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            if (x == m - 1 && y == n - 1) {
                return minObstacles[m - 1][n - 1];
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && minObstacles[nx][ny] == INT_MAX) {
                    if (grid[nx][ny] == 0) {
                        dq.push_front({ nx, ny });
                        minObstacles[nx][ny] = minObstacles[x][y];
                    } else {
                        dq.push_back({ nx, ny });
                        minObstacles[nx][ny] = minObstacles[x][y] + 1;
                    }
                }
            }
        }

        return -1;
    }
};

