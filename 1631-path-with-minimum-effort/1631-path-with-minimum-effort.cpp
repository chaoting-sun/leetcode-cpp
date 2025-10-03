
class Solution {
public:
    // Approach: Dijkstra
    // Time: O(mn*log(mn))
    // Space: O(mn)
    
    // using PI2 = pair<int,int>;

    // vector<int> dx = { 1, -1, 0, 0 };
    // vector<int> dy = { 0, 0, 1, -1 };

    // int minimumEffortPath(vector<vector<int>>& heights) {
    //     int m = heights.size(), n = heights[0].size();
    //     if (m == 0 || n == 0) return -1;
        
    //     priority_queue<PI2, vector<PI2>, greater<>> pq;
    //     vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

    //     pq.push({ 0, 0 });
    //     distance[0][0] = 0;

    //     while (!pq.empty()) {
    //         auto [currentDistance, position] = pq.top();
    //         int x = position / n, y = position % n;
    //         pq.pop();

    //         if (currentDistance != distance[x][y]) continue;
    //         if (x == m - 1 && y == n - 1) {
    //             return currentDistance;
    //         }

    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
    //             int newDistance = max(abs(heights[x][y] - heights[nx][ny]), distance[x][y]);
    //             if (newDistance < distance[nx][ny]) {
    //                 distance[nx][ny] = newDistance;
    //                 pq.push({ distance[nx][ny], nx * n + ny });
    //             }
    //         }
    //     }

    //     return -1;
    // }

    // DSU
    // Time: O(mn*log(mn))
    // Space: O(mn)

    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };

    vector<int> parent;
    vector<int> size;

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return -1;
        int n = heights[0].size();
        if (n == 0) return -1;

        if (m == 1 && n == 1) return 0; // early return for trivial case

        auto idx = [n](int i, int j) { return i * n + j; };

        vector<array<int, 3>> edges;
        edges.reserve(2*m*n - n - m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currentIndex = idx(i, j);
                int iDown = i + 1;
                if (iDown < m) {
                    int neighborIndex = idx(iDown, j);
                    edges.push_back({ abs(heights[i][j] - heights[iDown][j]), currentIndex, neighborIndex });
                }
                int jRight = j + 1;
                if (jRight < n) {
                    int neighborIndex = idx(i, jRight);
                    edges.push_back({ abs(heights[i][j] - heights[i][jRight]), currentIndex, neighborIndex });
                }
            }
        }

        sort(edges.begin(), edges.end(), [](array<int,3>& a, array<int,3>& b) {
            return a[0] < b[0];
        });

        int total = m * n;
        parent.resize(total);
        size.resize(total, 1);
        for (int i = 0; i < total; i++) parent[i] = i;

        int lastIndex = total - 1;
        for (int i = 0; i < edges.size(); i++) {
            auto [effort, u, v] = edges[i];
            unite(u, v);
            if (find(0) == find(lastIndex)) {
                return effort;
            }
        }

        return -1; // make compiler happy
    }
};