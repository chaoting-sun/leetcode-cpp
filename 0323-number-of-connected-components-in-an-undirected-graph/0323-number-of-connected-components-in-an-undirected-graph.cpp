class Solution {
public:
    void dfs(vector<vector<int>>& nodes, vector<bool>& visited, int currentNode) {
        visited[currentNode] = true;
        for (int nextNode: nodes[currentNode]) {
            if (!visited[nextNode]) {
                dfs(nodes, visited, nextNode);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // change to adjacency list

        // Time: O(V + E). initialize the entries + push back all edges
        // Space: O(V + E)
        vector<vector<int>> nodes(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        // do dfs and count the entries

        int numComponents = 0;
        vector<bool> visited(n, false);
        // Time: O(V + E). loop through V vertices + explore all edges
        // Space: O(V)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(nodes, visited, i);
                numComponents++;
            }
        }
        return numComponents;
    }

    // int countComponents(int n, vector<vector<int>>& edges) {

    // }
};