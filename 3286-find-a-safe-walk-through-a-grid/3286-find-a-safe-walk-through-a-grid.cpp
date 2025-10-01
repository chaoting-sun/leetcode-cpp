class Solution {
public:
    vector<int> dx = { 0, 0, -1, 1 };
    vector<int> dy = { -1, 1, 0, 0 };

    // Approach: BFS
    // Time: O(mn*health)
    // Space: O(mn*health)

    // bool findSafeWalk(vector<vector<int>>& grid, int health) {
    //     int m = grid.size(), n = grid[0].size();
    //     if (m == 0 || n == 0) return false;
        
    //     queue<array<int,3>> q; // x, y, remaining health
    //     vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(health+1, false)));

    //     q.push({ 0, 0, health - grid[0][0] });
    //     visited[0][0][health] = true;

    //     while (!q.empty()) {
    //         auto [x, y, remainingHealth] = q.front();
    //         q.pop();

    //         if (x == m - 1 && y == n - 1) {
    //             return true;
    //         }

    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
    //                 int newRemainingHealth = remainingHealth - grid[nx][ny];
    //                 if (newRemainingHealth <= 0 || visited[nx][ny][newRemainingHealth]) continue;
    //                 visited[nx][ny][newRemainingHealth] = true;
    //                 q.push({ nx, ny, newRemainingHealth });
    //             }
    //         }
    //     }

    //     return false;
    // }

    // Approach: 0-1 bfs
    // Time: O(V + E) = O(mn)
    // Space: O(mn)

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return false;
        
        deque<pair<int,int>> dq; // x, y
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dq.push_back({ 0, 0 });
        dist[0][0] = grid[0][0];

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            if (x == m - 1 && y == n - 1) {
                return dist[m - 1][n - 1] < health;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    if (grid[nx][ny] == 1) {
                        dq.push_back({ nx, ny });
                    } else {
                        dq.push_front({ nx, ny });
                    }
                }
            }
        }

        return false;
    }
};