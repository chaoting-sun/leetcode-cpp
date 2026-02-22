class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int n_left = n;
        
        while (n_left > 2) {
            int size = q.size();
            n_left -= size;
            while (size--) {
                int curr = q.front();
                q.pop();
                // remove the edge of curr
                for (int neighbor: adj[curr]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

// trap path:
// n = 4, edges = [[0,1],[1,2],[2,3]]
// trace:
// adj
// 0: 1
// 1: 0 2
// 2: 1 3
// 3: 2
// degree = [1,1,1,1]
// q = [0, 3]
// n_left = 4
// n_left = 2
// curr = 0, q = [3]
// q = [3,1]
// curr = 3, q = [1]
// q = [1,2]
// ans = [1,2]
// < returns [1,2]

// happy path:
// n = 3, edges = [[0,1], [1,2]] -> 0--1--2
// trace:
// adj
// 0: 1
// 1: 0 2
// 2: 1
// degree = [1,0,1]
// q = [0,2]
// n_left = 3
// n_left = 1
// curr = 0, q = [2]
// q = [2, 1]
// curr = 2
// q = [1]
// ans = [1]
// returns 1

// base case:
// n = 1, edges = [[]]
// < returns [0]

// base case:
// n = 2, edges = [[0, 1]] -> 0--1
// trace:
// adj
// 0: 1
// 1: 0
// degree = [1,1]
// q = [0,1]
// < returns [0,1]