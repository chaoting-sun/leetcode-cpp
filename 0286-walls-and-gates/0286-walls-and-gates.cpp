const int GATE = 0;
const int EMPTY = 2147483647;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> pos;
        vector<int> di { -1, 1, 0, 0 };
        vector<int> dj { 0, 0, -1, 1 };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == GATE) {
                    pos.push({ i, j });
                }
            }
        }

        while (!pos.empty()) {
            int ci = pos.front().first;
            int cj = pos.front().second;
            pos.pop();

            for (int k = 0; k < 4; k++) {
                int ni = ci + di[k];
                int nj = cj + dj[k];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n || rooms[ni][nj] != EMPTY)
                    continue;
                
                rooms[ni][nj] = rooms[ci][cj] + 1;
                pos.push({ ni, nj });
            }
        }
    }
};