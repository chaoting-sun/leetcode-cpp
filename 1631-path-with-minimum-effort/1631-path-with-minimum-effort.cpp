// Approach: Dijkstra
// Time: O(mn*log(mn))
// Space: O(mn)

// using PI2 = pair<int,int>;

// class Solution {
// public:
//     vector<int> dx = { 1, -1, 0, 0 };
//     vector<int> dy = { 0, 0, 1, -1 };

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size(), n = heights[0].size();
//         if (m == 0 || n == 0) return -1;
        
//         priority_queue<PI2, vector<PI2>, greater<>> pq;
//         vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

//         pq.push({ 0, 0 });
//         distance[0][0] = 0;

//         while (!pq.empty()) {
//             auto [currentDistance, position] = pq.top();
//             int x = position / n, y = position % n;
//             pq.pop();

//             if (currentDistance != distance[x][y]) continue;
//             if (x == m - 1 && y == n - 1) {
//                 return currentDistance;
//             }

//             for (int i = 0; i < 4; i++) {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
//                 int newDistance = max(abs(heights[x][y] - heights[nx][ny]), distance[x][y]);
//                 if (newDistance < distance[nx][ny]) {
//                     distance[nx][ny] = newDistance;
//                     pq.push({ distance[nx][ny], nx * n + ny });
//                 }
//             }
//         }

//         return -1;
//     }    
// };


// Kruskal's Algorithm
// Time: O(mn*log(mn))
// Space: O(mn)

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n): parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
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
};

struct Edge {
    int u;
    int v;
    int w;
    bool operator<(Edge& other) const {
        return w < other.w;
    };
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return -1;
        int n = heights[0].size();
        if (n == 0) return -1;

        if (m == 1 && n == 1) return 0; // early return for trivial case

        auto idx = [n](int i, int j) { return i * n + j; };
        
        int total = m * n;
        vector<Edge> edges;
        edges.reserve(2 * total - n - m);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currentIndex = idx(i, j);
                if (i + 1 < m) {
                    edges.emplace_back(Edge{
                        idx(i, j),
                        idx(i + 1, j),
                        abs(heights[i][j] - heights[i + 1][j])
                    });
                }
                if (j + 1 < n) {
                    edges.emplace_back(Edge{
                        idx(i, j),
                        idx(i, j + 1),
                        abs(heights[i][j] - heights[i][j + 1])
                    });
                }
            }
        }

        sort(edges.begin(), edges.end());
        
        DSU dsu(total);
        int lastIndex = total - 1;
        
        for (Edge& e: edges) {
            dsu.unite(e.u, e.v);
            if (dsu.find(0) == dsu.find(lastIndex)) return e.w;
        }

        return -1; // make compiler happy
    }
};