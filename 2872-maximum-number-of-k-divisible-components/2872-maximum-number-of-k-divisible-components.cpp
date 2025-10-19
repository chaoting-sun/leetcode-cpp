// Approach: DFS
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int ans = 0;
    vector<vector<int>> g;
    vector<int> remainder;

    void dfs(vector<int>& values, int root, int f, int k, vector<int>& remainder) {
        for (int v: g[root]) {
            if (f == v) continue;
            dfs(values, v, root, k, remainder);
            remainder[root] += remainder[v];
        }
        remainder[root] += values[root];
        remainder[root] %= k;
        if (remainder[root] == 0) {
            ans++;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {         
        g.resize(n);
        remainder.resize(n);

        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(values, 0, -1, k, remainder);
        return ans;
    }
};