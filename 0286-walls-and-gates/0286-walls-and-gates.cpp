class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int i, int j, int step) {
        int m = rooms.size();
        int n = rooms[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (rooms[i][j] == -1 || rooms[i][j] == 0) return;

        step++;
        int tmp = min(rooms[i][j], step);
        rooms[i][j] = -1;

        dfs(rooms, i + 1, j, step);
        dfs(rooms, i - 1, j, step);
        dfs(rooms, i, j + 1, step);
        dfs(rooms, i, j - i, step);

        rooms[i][j] = tmp;
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    dfs(rooms, i + 1, j, 0);
                    dfs(rooms, i - 1, j, 0);
                    dfs(rooms, i, j + 1, 0);
                    dfs(rooms, i, j - 1, 0);
                }
            }
        }
    }
};