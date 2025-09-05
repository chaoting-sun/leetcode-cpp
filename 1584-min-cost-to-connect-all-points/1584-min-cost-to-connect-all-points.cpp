struct Edge {
    int u;
    int v;
    int w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

class Solution {
    vector<int> parent;
    vector<int> size;

public:
    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            parent[u] = v;
            size[v] += size[u];
        }
    }

    int find_set(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find_set(parent[u]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({ i, j, w });
            }
        }

        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        sort(edges.begin(), edges.end(), [&](Edge &e1, Edge &e2) {
            return e1.w < e2.w;
        });

        int cost = 0;
        for (auto &edge: edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (find_set(u) != find_set(v)) {
                cost += w;
                union_sets(u, v);
            }
        }

        return cost;
    }
};