using PI2 = pair<int,int>;

class Solution {
public:
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = {  0, 0, 1, -1 };

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        
        priority_queue<PI2, vector<PI2>, greater<>> pq;
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        pq.push({ 0, 0 }); // min removed obstacles, position
        minObstacles[0][0] = 0;

        while (!pq.empty()) {
            auto [removed, position] = pq.top();
            pq.pop();
            int x = position / n, y = position % n;

            if (removed > minObstacles[x][y]) continue;
            if (x == m - 1 && y == n - 1) return removed;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nPosition = nx * n + ny;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && minObstacles[nx][ny] == INT_MAX) {
                    // relax
                    int nRemoved = removed + grid[nx][ny];
                    if (nRemoved < minObstacles[nx][ny]) {
                        minObstacles[nx][ny] = nRemoved;
                        pq.push({ nRemoved, nPosition });
                    }
                }
            }
        }

        return -1;
    }

    // Approach: Deque

    // int minimumObstacles(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     if (m == 0 || n == 0) return 0;

    //     vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
    //     deque<pair<int,int>> dq; // x, y
    //     dq.push_back({ 0, 0 });
    //     minObstacles[0][0] = 0;

    //     while (!dq.empty()) {
    //         auto [x, y] = dq.front();
    //         dq.pop_front();
    //         if (x == m - 1 && y == n - 1) {
    //             return minObstacles[m - 1][n - 1];
    //         }
    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx >= 0 && nx < m && ny >= 0 && ny < n && minObstacles[nx][ny] == INT_MAX) {
    //                 if (grid[nx][ny] == 0) {
    //                     dq.push_front({ nx, ny });
    //                     minObstacles[nx][ny] = minObstacles[x][y];
    //                 } else {
    //                     dq.push_back({ nx, ny });
    //                     minObstacles[nx][ny] = minObstacles[x][y] + 1;
    //                 }
    //             }
    //         }
    //     }

    //     return -1;
    // }
};

