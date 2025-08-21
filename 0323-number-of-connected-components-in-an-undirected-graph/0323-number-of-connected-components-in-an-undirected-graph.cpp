class Solution {
public:
    // Approach: DFS
    // Time: 

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr_node) {
        visited[curr_node] = true;

        for (int next_node: adj[curr_node]) {
            if (!visited[next_node]) {
                dfs(adj, visited, next_node);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // Time: O(E)
        // Space: O(V + E)
        vector<vector<int>> adj(n);
        for (vector<int> edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Time: O(V)
        // Space: O(V)
        vector<bool> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                count++;
            }
        }
        
        return count;
    }
};