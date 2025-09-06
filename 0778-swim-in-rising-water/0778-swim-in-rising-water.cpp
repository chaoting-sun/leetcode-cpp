class Solution {
public:
    // Approach: Modified BFS with Min-Heap
    // Intuition: The problem asks for the minimum time required to travel 
    // from (0,0) to (m-1,n-1). This suggests BFS, because we are essentially 
    // searching for the "shortest path".
    //
    // However, a normal BFS uses a queue (FIFO), which expands cells in 
    // order of discovery. In this problem, the traversal time depends on 
    // the cell's height h, and we want to minimize the maximum height along 
    // the path. Therefore, instead of a regular queue, we should use a min-heap 
    // (priority queue) sorted by height h. This way, the cell with the smallest 
    // height is always expanded first.
    //
    // For each popped cell:
    //   - If h <= time, we can move to it immediately.
    //   - If h > time, we must "wait" until time = h before moving further.
    // In other words, time = max(time, h).
    //
    // Once we pop the destination cell (m-1,n-1), the current `time` is the answer.
    //
    // Complexity:
    //   Time:  O(m*n * log(m*n)) due to heap operations
    //   Space: O(m*n) for visited states and heap storage

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        using unit = pair<int,int>;
        priority_queue<unit, vector<unit>, greater<unit>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<int> i_diff { -1, 1, 0, 0 }, j_diff { 0, 0, -1, 1 };

        int time = 0;
        pq.push({ grid[0][0], 0 });

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int ci = pos / m, cj = pos % n;
            visited[ci][cj] = true;
            
            if (h > time) {
                time = h;           
            }

            // termination condition
            if (ci == m - 1 && cj == n - 1) return time;

            for (int p = 0; p < 4; p++) {
                int ni = ci + i_diff[p];
                int nj = cj + j_diff[p];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    pq.push({ grid[ni][nj], { ni * m + nj } });
                    visited[ni][nj] = true;
                }
            }
        }

        return -1;
    }
};
