class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        if (n == 2) return { 0, 1 };

        // compute the degree of each node
        // build an adjacency list
        vector<int> node_degree(n);
        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            node_degree[u]++;
            node_degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS:
        // we remove the nodes layer by layer using BFS
        // we start by pushing all nodes with degree 1 into the queue
        // In each layer, we remove the node, and push their adjacent nodes if they become 1 degree
        // when the left nodes <= 2 nodes, then the left nodes are the center nodes.
        queue<int> nodes;
        for (int i = 0; i < n; i++) {
            if (node_degree[i] == 1) nodes.push(i);
        }

        int node_count = n;
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                int u = nodes.front();
                nodes.pop();
                node_count--;

                for (int v: adj[u]) {
                    node_degree[v]--;
                    if (node_degree[v] == 1) {
                        nodes.push(v);
                    }
                }
            }
            if (node_count <= 2) break;
        }

        vector<int> left_nodes;
        while (!nodes.empty()) {
            left_nodes.push_back(nodes.front());
            nodes.pop();
        }
        return left_nodes;
    }
};

// Dry Run

// node_degree = [1, 3, 1, 1]
// adj
// 0 -> 1
// 1 -> 0 2 3
// 2 -> 1
// 3 -> 1
// BFS
// nodes = [0, 2, 3]
// node_count = 4

// pop 0, nodes = [2,3]
// node_count = 3
// node_degree = [1, 2, 1, 1]

// pop 2, nodes = [3]
// node_count = 2
// node_degree = [1, 1, 1, 1]
// nodes = [3, 1]

// pop 3, nodes = [1]
// node_count = 1
// node_degree = [1, 0, 1, 1]


// Submit Error

// 1. wrong API name
// left_nodes.push(nodes.front());
// left_nodes.push_back(nodes.front());

// 2. edge case
// n == 1, edges = []
// n == 2, edges = [[0,1]]