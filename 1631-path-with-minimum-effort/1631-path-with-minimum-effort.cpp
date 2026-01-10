class Solution {
private:
    vector<int> x_directions = { 1, -1, 0, 0 };
    vector<int> y_directions = { 0, 0, 1, -1 };

    bool canReach(const vector<vector<int>>& heights, int limit) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == m - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int new_x = x + x_directions[i];
                int new_y = y + y_directions[i];
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && abs(heights[x][y] - heights[new_x][new_y]) <= limit) {
                    q.push({ new_x, new_y });
                    visited[new_x][new_y] = true;
                }
            }
        }
        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        int global_max_effort = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < m - 1) {
                    global_max_effort = max(global_max_effort, abs(heights[i][j] - heights[i + 1][j]));
                }
                if (j < n - 1) {
                    global_max_effort = max(global_max_effort, abs(heights[i][j] - heights[i][j + 1]));
                }
            }
        }

        int left = 0;
        int right = global_max_effort;
        // F...FT...T
        //  l   l
        //      r   r
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canReach(heights, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};