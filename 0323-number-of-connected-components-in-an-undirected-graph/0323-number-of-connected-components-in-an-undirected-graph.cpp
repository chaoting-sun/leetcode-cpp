class Solution {
private:
    void DfsGraph(const vector<vector<int>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;
        for (const int v: adj[u]) {
            if (!visited[v]) {
                DfsGraph(adj, visited, v);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(n);

        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // iterate from 0 to n - 1, start dfs if unvisited
        // count the number of times that dfs is done

        int num_connected_components = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DfsGraph(adj, visited, i);
                num_connected_components++;
            }
        }

        return num_connected_components;
    }
};

// Submit Errors

// visited is typed as const but being modified inside
// void DfsGraph(const vector<vector<int>>& adj, const vector<bool>& visited, int u) {
//     visited[u] = true;

// for (const int& edge: edges)
// for (const auto& edge: edges)