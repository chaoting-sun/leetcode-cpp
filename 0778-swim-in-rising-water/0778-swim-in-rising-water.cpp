class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        using unit = pair<int, vector<int>>; // height, position (i, j)
        priority_queue<unit, vector<unit>, greater<unit>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<int> i_diff { -1, 1, 0, 0 }, j_diff { 0, 0, -1, 1 };

        int time = 0;
        pq.push({ grid[0][0], { 0, 0 } });

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int ci = pos[0], cj = pos[1];
            visited[ci][cj] = true;
            
            if (h >= time) {
                time = h;           
            }

            // termination condition
            if (ci == m - 1 && cj == n - 1) return time;

            for (int p = 0; p < 4; p++) {
                int ni = ci + i_diff[p];
                int nj = cj + j_diff[p];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    pq.push({ grid[ni][nj], { ni, nj } });
                    visited[ni][nj] = true;
                }
            }
        }

        return -1;
    }
};

// q = [ (0,(0,0)) ]
// time = 0

// pop q -> q = []
// h = 0, pos = (0,0)
// visited[0][0] = true
// time = 0
// push to q -> q = [ (1,(1,0)), (2,(0,1)) ]

// pop q -> q = [ (2,(0,1)) ]
// h = 1, pos = (1,0)
// visited[1][0] = true
// time = 1
// push to q -> q = [ (2,(0,1)), (3, (1,1)) ]