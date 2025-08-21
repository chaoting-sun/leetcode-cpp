class Solution {
public:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int prev, int curr) {
        if (visited[curr] == 1) return true;
        if (visited[curr] == 2) return false;

        visited[curr] = 1;
        for (int neighbor: graph[curr]) {
            if (prev == neighbor) continue;
            if (hasCycle(graph, visited, curr, neighbor)) {
                return true;
            }
        }
        visited[curr] = 2;
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);

        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            vector<int> visited(n + 1, 0);
            if (hasCycle(graph, visited, 0, edge[0])) {
                return edge;
            }
        }
        return {};
    }
};