class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dRows = { 1, -1, 0, 0 };
        vector<int> dCols = { 0, 0, 1, -1 };
        
        vector<vector<vector<int>>> minDistance(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        queue<pair<int,int>> q; // distance, current obstacles
        q.push({ 0, 0 });
        minDistance[0][0][0] = 0;

        while (!q.empty()) {
            auto [p, obstacles] = q.front();
            q.pop();
            int r = p / n;
            int c = p % n;
            for (int i = 0; i < 4; i++) {
                int newR = r + dRows[i];
                int newC = c + dCols[i];
                if (newR < 0 || newR >= m || newC < 0 || newC >= n) continue;
                
                int newObstacles = obstacles + (grid[newR][newC] == 1 ? 1 : 0);
                
                if (newObstacles > k) continue; // invalid move
                if (minDistance[newR][newC][newObstacles] != INT_MAX) continue; // visited

                minDistance[newR][newC][newObstacles] = minDistance[r][c][obstacles] + 1;
                q.push({ newR * n + newC, newObstacles });
            }
        }
        int minSteps = INT_MAX;
        for (int i = 0; i <= k; i++) {
            minSteps = min(minSteps, minDistance[m - 1][n - 1][i]);
        }
        return minSteps == INT_MAX ? -1 : minSteps;
    }
};