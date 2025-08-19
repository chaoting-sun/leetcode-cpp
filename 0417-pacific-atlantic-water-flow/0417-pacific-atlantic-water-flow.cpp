class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac_visited(m, vector<bool>(n, false));
        vector<vector<bool>> atl_visited(m, vector<bool>(n, false));

        vector<int> dx { 0, 0, 1, -1 };
        vector<int> dy { 1, -1, 0, 0 };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0) && !pac_visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    pac_visited[i][j] = true;

                    while (!q.empty()) {
                        int size = q.size();

                        for (int k = 0; k < size; k++) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();

                            for (int l = 0; l < 4; l++) {
                                int nx = x + dx[l];
                                int ny = y + dy[l];

                                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !pac_visited[nx][ny] && heights[x][y] <= heights[nx][ny]) {
                                    q.push({ nx, ny });
                                    pac_visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
                if ((i == m - 1 || j == n - 1) && !atl_visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    atl_visited[i][j] = true;

                    while (!q.empty()) {
                        int size = q.size();

                        for (int k = 0; k < size; k++) {
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();

                            for (int l = 0; l < 4; l++) {
                                int nx = x + dx[l];
                                int ny = y + dy[l];

                                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !atl_visited[nx][ny] && heights[x][y] <= heights[nx][ny]) {
                                    q.push({ nx, ny });
                                    atl_visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }

            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac_visited[i][j] && atl_visited[i][j]) {
                    ans.push_back({ i, j });
                }
            }
        }

        return ans;
    }
};