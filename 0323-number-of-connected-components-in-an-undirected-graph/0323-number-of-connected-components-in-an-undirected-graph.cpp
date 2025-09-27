class Solution {
public:
    // Approach: DFS
    // Time: O(V + E)
    // Space: O(V + E)

    // void dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr_node) {
    //     visited[curr_node] = true;

    //     for (int next_node: adj[curr_node]) {
    //         if (!visited[next_node]) {
    //             dfs(adj, visited, next_node);
    //         }
    //     }
    // }

    // int countComponents(int n, vector<vector<int>>& edges) {
    //     // Time: O(V + E)
    //     // Space: O(V + E)
    //     vector<vector<int>> adj(n);
    //     for (vector<int> edge: edges) {
    //         adj[edge[0]].push_back(edge[1]);
    //         adj[edge[1]].push_back(edge[0]);
    //     }
        
    //     // Time: O(V + E). we only traverse those nodes that are not visited
    //     // Space: O(V)
    //     vector<bool> visited(n);
    //     int count = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) {
    //             dfs(adj, visited, i);
    //             count++;
    //         }
    //     }
        
    //     return count;
    // }


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
        vector<vector<int>> nodes(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        // do dfs and count the entries
        int numComponents = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(nodes, visited, i);
                numComponents++;
            }
        }
        return numComponents;
    }
};