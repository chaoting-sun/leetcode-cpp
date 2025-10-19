class Solution {
public:
    int ans = 0;

    int dfs(vector<vector<int>>& nodes, vector<int>& values, int root, int f, int k, vector<int>& subtreeSumModK) {
        for (int v: nodes[root]) {
            if (f == v) continue;
            subtreeSumModK[root] += dfs(nodes, values, v, root, k, subtreeSumModK);
        }
        subtreeSumModK[root] += values[root];
        subtreeSumModK[root] %= k;
        if (subtreeSumModK[root] == 0) ans++;
        return subtreeSumModK[root];
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {         
        vector<vector<int>> nodes(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        vector<int> subtreeSumModK(n);
        dfs(nodes, values, 0, -1, k, subtreeSumModK);
        return ans;
    }
};