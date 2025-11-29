class Solution {
public:
    void dfs(int u, int ancestor, vector<vector<int>>& graph, vector<vector<int>>& ans) {
        for (int v: graph[u]) {
            if (!ans[v].empty() && ans[v].back() == ancestor) {
                continue;
            }
            ans[v].push_back(ancestor);
            dfs(v, ancestor, graph, ans);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(0));
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
        }

        vector<vector<int>> ans(n, vector<int>(0));
        for (int i = 0; i < n; i++) {
            if (!graph[i].empty()) {
                dfs(i, i, graph, ans);
            }
        }

        return ans;
    }

    // vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    //     vector<int> inDegree(n);
    //     vector<vector<int>> graph(n, vector<int>(0));

    //     for (auto& e: edges) {
    //         int u = e[0], v = e[1];
    //         graph[u].push_back(v);
    //         inDegree[v]++;
    //     }

    //     queue<int> q;
    //     for (int i = 0; i < n; i++) {
    //         if (inDegree[i] == 0) {
    //             q.push(i);
    //         }
    //     }

    //     vector<unordered_set<int>> ancestors(n);
    //     vector<bool> seen(n, false);

    //     while (!q.empty()) {
    //         int u = q.front();
    //         q.pop();
    //         for (int v: graph[u]) {
    //             ancestors[v].insert(u);
    //             for (const int pre: ancestors[u]) {
    //                 ancestors[v].insert(pre);
    //             }
    //             if (!seen[v]) {
    //                 q.push(v);
    //             } else {
    //                 seen[v] = true;
    //             }
    //         }
    //     }

    //     vector<vector<int>> ans(n);
    //     for (int v = 0; v < n; v++) {
    //         for (const int u: ancestors[v]) {
    //             ans[v].push_back(u);
    //         }
    //         sort(ans[v].begin(), ans[v].end());
    //     }
    //     return ans;
    // }
};