// Kruskal's Algorithm
// Time: O(ElogE)
// Space: O(V + E)

// struct Edge {
//     int u;
//     int v;
//     int w;
//     Edge(int u, int v, int w): u(u), v(v), w(w) {}
// };

// class Solution {
//     vector<int> parent;
//     vector<int> size;

// public:
//     void union_sets(int u, int v) {
//         u = find_set(u);
//         v = find_set(v);
//         if (u != v) {
//             if (size[u] > size[v]) {
//                 swap(u, v);
//             }
//             parent[u] = v;
//             size[v] += size[u];
//         }
//     }

//     int find_set(int u) {
//         if (u == parent[u])
//             return u;
//         return parent[u] = find_set(parent[u]);
//     }

//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         vector<Edge> edges;

//         // Time: O(V^2)
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                 edges.push_back({ i, j, w });
//             }
//         }

//         // Time: O(E*logE) = O(V^2*logV)
//         sort(edges.begin(), edges.end(), [&](Edge &e1, Edge &e2) {
//             return e1.w < e2.w;
//         });

//         parent.resize(n);
//         size.resize(n, 1);
//         for (int i = 0; i < n; i++) parent[i] = i;

//         int cost = 0;
//         // Time: O(alpha*E) = O(alpha*V^2)
//         for (auto &edge: edges) {
//             int u = edge.u;
//             int v = edge.v;
//             int w = edge.w;

//             if (find_set(u) != find_set(v)) {
//                 cost += w;
//                 union_sets(u, v);
//             }
//         }

//         return cost;
//     }
// };

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[i][j] = w;
                edges[j][i] = w;
            }
        }

        int cost = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight, vertex
        unordered_set<int> visited;
        pq.push({ 0, 0 });

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (visited.count(u)) continue;

            cost += w;

            visited.insert(u);

            for (int v = 0; v < n; v++) {
                if (!visited.count(v)) {
                    pq.push({ edges[u][v], v });
                }
            }
        }

        return cost;
    }
};