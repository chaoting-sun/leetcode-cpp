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
    //   Time:  O(m*n * log(m*n)) due to heap operations. if m = n then O(n^2*logn)
    //   Space: O(m*n) for visited states and heap storage

    // int swimInWater(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     using unit = pair<int,int>;
    //     priority_queue<unit, vector<unit>, greater<unit>> pq;
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
        
    //     vector<int> i_diff { -1, 1, 0, 0 }, j_diff { 0, 0, -1, 1 };

    //     int time = 0;
    //     pq.push({ grid[0][0], 0 });

    //     while (!pq.empty()) {
    //         auto [h, pos] = pq.top();
    //         pq.pop();
    //         int ci = pos / m, cj = pos % n;
    //         visited[ci][cj] = true;
            
    //         if (h > time) {
    //             time = h;           
    //         }

    //         // termination condition
    //         if (ci == m - 1 && cj == n - 1) return time;

    //         for (int p = 0; p < 4; p++) {
    //             int ni = ci + i_diff[p];
    //             int nj = cj + j_diff[p];
    //             if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
    //                 pq.push({ grid[ni][nj], { ni * m + nj } });
    //                 visited[ni][nj] = true;
    //             }
    //         }
    //     }

    //     return -1;
    // }

    // Approach: Binary Search
    // Intuition: 這題的 grid[i][j] 有給明確的範圍，0 <= grid[i][j] < n^2，所以可以利用 binary search 嘗試
    // 最小但可以從起點走到終點的時間，這與常見的 binary search 題目中常見的問題 "尋找第一個不小於給定的數" 基本上一樣。
    // 要辨別能不能在給定的時間內走到，可以用 DFS
    // Time: O(mn*log(mn)) = O(n^2*logn).
    // Space: O(mn) = O(n^2)

    // vector<int> i_diff { -1, 1, 0, 0 }, j_diff { 0, 0, -1, 1 };

    // int swimInWater(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     int left = 0, right = m * n - 1;

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (isReachable(grid, mid)) {
    //             right = mid;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return right;
    // }

    // bool isReachable(vector<vector<int>>& grid, int time) {
    //     if (grid[0][0] > time) return false;
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     stack<pair<int,int>> stk;
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
    //     stk.push({ 0, 0 });

    //     while (!stk.empty()) {
    //         auto [ci, cj] = stk.top();
    //         stk.pop();
            
    //         if (ci == m - 1 && cj == n - 1) return true;

    //         visited[ci][cj] = true;

    //         for (int p = 0; p < 4; p++) {
    //             int ni = ci + i_diff[p];
    //             int nj = cj + j_diff[p];
    //             if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj] <= time) {
    //                 stk.push({ ni, nj });
    //             }
    //         }
    //     }

    //     return false;
    // }

    // Kruskal's Algorithm

    vector<int> parent;
    vector<int> size;
    vector<int> i_diff { -1, 1, 0, 0 }, j_diff { 0, 0, -1, 1 };

    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int n_cells = m * n;

        parent.resize(n_cells, 0);
        size.resize(n_cells, 1);
        for (int i = 0; i < n_cells; i++) parent[i] = i;

        vector<pair<int, int>> nodes(n_cells);

        for (int i = 0; i < n_cells; i++) nodes[i] = { grid[i / n][i % n], i };
        sort(nodes.begin(), nodes.end(), [&](pair<int,int> &a, pair<int,int> &b) {
            return a.first < b.first;
        });

        vector<vector<bool>> opened(m, vector<bool>(n, false));

        for (int i = 0; i < n_cells; i++) {
            auto [h, pos] = nodes[i];
            int ci = pos / n;
            int cj = pos % n;
            
            opened[ci][cj] = true;
            
            for (int p = 0; p < 4; p++) {
                int ni = ci + i_diff[p];
                int nj = cj + j_diff[p];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && opened[ni][nj]) {
                    union_sets(ci * n + cj, ni * n + nj);
                }
            }

            if (find_set(0) == find_set(n_cells - 1)) return h;
        }

        return -1;
    }
};
