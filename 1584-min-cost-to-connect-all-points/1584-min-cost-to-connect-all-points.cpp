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

// Prim's Algorithm


class Solution {
public:

    // basic
    // Time: O(V^2*logV)
    // Space: O(V^2)

    // int minCostConnectPoints(vector<vector<int>>& points) {
    //     int n = points.size();

    //     int cost = 0;

    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight, vertex
    //     vector<bool> visited(n, false);
    //     pq.push({ 0, 0 });

    //     // Time: O(E*logE) = O(V^2*logV)
    //     // in worst case we push/pop every edge in the heap. for every op it takes logE time
    //     while (!pq.empty()) {
    //         auto [w, u] = pq.top();
    //         pq.pop();

    //         if (visited[u]) continue;
    //         cost += w;
    //         visited[u] = true;

    //         for (int v = 0; v < n; v++) {
    //             if (!visited[v]) {
    //                 int w_uv = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
    //                 pq.push({ w_uv, v });
    //             }
    //         }
    //     }

    //     return cost;
    // }

    // optimized
    // Time: O(V^2)
    // Space: O(v)

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dist_from_mst(n, INT_MAX);
        vector<bool> visited(n, false);

        // start from 0
        for (int i = 0; i < n; i++) {
            int dist = abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]);
            dist_from_mst[i] = dist;
        }

        int cost = 0;
        int n_visited = 0;

        while (n_visited < n) {
            int min_dist = INT_MAX, min_dist_v = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist_from_mst[i] < min_dist) {
                    min_dist = dist_from_mst[i];
                    min_dist_v = i;
                }
            }
            
            cost += min_dist;
            visited[min_dist_v] = true;
            n_visited += 1;
            
            for (int i = 0; i < n; i++) {
                int dist = abs(points[i][0] - points[min_dist_v][0]) + abs(points[i][1] - points[min_dist_v][1]);
                dist_from_mst[i] = min(dist_from_mst[i], dist);
            }
        }

        return cost;
    }
};