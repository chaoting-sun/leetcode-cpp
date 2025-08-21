class Solution {
public:
    // Approach: DFS (recursive)
    // Time: O(E + V)
    // Space: O(E + V)

    // bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int prev, int curr, int& count) {
    //     if (visited[curr]) return true;

    //     visited[curr] = true;
    //     count++;

    //     for (int next: adj[curr]) {
    //         if (next == prev) continue;
    //         if (hasCycle(adj, visited, curr, next, count)) {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // bool validTree(int n, vector<vector<int>>& edges) {
    //     vector<vector<int>> adj(n);
    //     // Time: O(E)
    //     // Space: O(E + V)
    //     for (vector<int> edge: edges) {
    //         adj[edge[0]].push_back(edge[1]);
    //         adj[edge[1]].push_back(edge[0]);
    //     }

    //     vector<bool> visited(n, 0);
        
    //     int count = 0;
    //     // Time: O(E + V)
    //     bool exist_cycle = hasCycle(adj, visited, -1, 0, count);
        
    //     if (exist_cycle || count != n) return false;
    //     return true;
    // }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        // Time: O(E)
        // Space: O(E + V)
        for (vector<int> edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent; // child -> parent
        
        stack<int> stk;
        stk.push(0);
        parent[0] = -1;
        int count = 0;

        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            for (int neighbor: adj[curr]) {
                // it is its parent
                if (parent.count(curr) && parent[curr] == neighbor) {
                    continue;
                }
                // neighbor has been visited -> has cycle
                if (parent.count(neighbor)) {
                    return false;
                }
                stk.push(neighbor);
                parent[neighbor] = curr;
            }
        }

        return parent.size() == n;
    }
};