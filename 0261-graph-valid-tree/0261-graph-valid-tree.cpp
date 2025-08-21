class Solution {
public: 
    bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int prev, int curr, int& count) {
        if (visited[curr]) return true;

        visited[curr] = true;
        count++;

        for (int next: adj[curr]) {
            if (next == prev) continue;
            if (hasCycle(adj, visited, curr, next, count)) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (vector<int> edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, 0);
        
        int count = 0;
        bool exist_cycle = hasCycle(adj, visited, -1, 0, count);
        
        if (exist_cycle || count != n) return false;
        return true;
    }
};