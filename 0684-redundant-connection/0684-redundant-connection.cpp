class Solution {
public:
    // Approach: build the graph and every time check if cycle exists every time
    // Time: O(V^2)
    // Intialize and construct adjacency list: O(E + V) = O(V)
    // DFS: O(E*(E + V)) = O(V^2)
    // Space: O(V)
    // visited: O(V)
    // adjacency list: O(E + V) = O(V)

    // bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int prev, int curr) {
    //     if (visited[curr] == 1) return true;
    //     if (visited[curr] == 2) return false;

    //     visited[curr] = 1;
    //     for (int neighbor: graph[curr]) {
    //         if (prev == neighbor) continue;
    //         if (hasCycle(graph, visited, curr, neighbor)) {
    //             return true;
    //         }
    //     }
    //     visited[curr] = 2;
    //     return false;
    // }

    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     int n = edges.size();
    //     vector<vector<int>> graph(n + 1);

    //     for (auto edge: edges) {
    //         graph[edge[0]].push_back(edge[1]);
    //         graph[edge[1]].push_back(edge[0]);
    //         vector<int> visited(n + 1, 0);
    //         if (hasCycle(graph, visited, 0, edge[0])) {
    //             return edge;
    //         }
    //     }
    //     return {};
    // }

    vector<int> parent;
    vector<int> size;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    int union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);

        if (u != v) {
            if (size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
            return 0;
        } else {
            return 1;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // # vertices = # edges
        parent.resize(n + 1, -1);
        size.resize(n + 1, -1);

        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if (parent[u] == -1) make_set(u);
            if (parent[v] == -1) make_set(v);
            int res = union_sets(u, v);
            if (res == 1) {
                return edge;
            }
        }
        return {};
    }
};