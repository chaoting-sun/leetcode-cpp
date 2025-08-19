class Solution {
public:
    // Approach: BFS
    // Time: O(m*n)
    // Space: O(m*n). in worst case there are all rotten oranges

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                } else if (grid[i][j] == 1) {
                    total++;
                }
            }
        }

        vector<int> dx { 1, -1, 0, 0 };
        vector<int> dy { 0, 0, 1, -1 };
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int count = 0;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !seen[nx][ny]) {
                        seen[nx][ny] = true;
                        q.push({ nx, ny });
                        count++;
                    }
                }
            }

            if (!q.empty()) {
                time++;
            }
        }

        return count == total ? time : -1;
    }
};
