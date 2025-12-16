// ## Understand

// May I ask what is the range of n?
//  - 1 <= n <= 50
// May I ask what is the length of edges?
//  - 0 <= edges.length <= n * (n - 1) / 2
// May I ask if there exists self-loops?
//  - ai != bi


// Match

// For a graph which is a complete connected components, it has n * (n - 1) / 2 edges,
// where n is the number of nodes. Therefore, my strategy is to iterate nodes, and
// do DFS from which is unvisited. During the DFS, I count the nodes and the edges.
// if the number of edges equals to nodes * (nodes -  1) / 2 then it is a complete
// connected components.


// Plan

// I will build an adjacency list from edges, and iterate each node. If a node is unvisited,
// I do a DFS from this node. In the DFS, I count the number of nodes and edges and
// explore the neighbor nodes. After each DFS, If the total edges = (total nodes) * (total nodes - 1) / 2,
// then add the total complete connect component by 1.


// Implementation


class Solution {
    struct DSU {
        vector<int> size;
        vector<int> parent;
        vector<int> edge_count;

        DSU(int n) {
            size.resize(n);
            parent.resize(n);
            edge_count.resize(n);

            for (int i = 0; i < n; i++) size[i] = 1;
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int u) {
            if (parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u != v) {
                if (size[u] > size[v]) {
                    swap(size[u], size[v]);
                }
                // size of v is larger than u
                parent[u] = v;
                size[v] += size[u];
                edge_count[v] += edge_count[u] + 1;
            } else {
                edge_count[v]++;
            }
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu = DSU(n);
        
        for (const auto& edge: edges) {
            dsu.unite(edge[0], edge[1]);
        }

        int complete_component_count = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.parent[i] == i) {
                int nodes = dsu.size[i];
                int edges = dsu.edge_count[i];
                bool is_complete = edges == nodes * (nodes - 1) / 2;
                if (is_complete) {
                    complete_component_count++;
                }
            }
        }

        return complete_component_count;
    }
};

// class Solution {
// private:
//     // return: total edges & total nodes
//     pair<int,int> exploreConnectedComponent(const vector<vector<int>>& adj, vector<bool>& visited, int current_node) {
//         visited[current_node] = true;
//         int total_nodes = 1;
//         int total_edges = adj[current_node].size();
//         for (int neighbor: adj[current_node]) {
//             if (!visited[neighbor]) {
//                 auto [neighbor_total_nodes, neighbor_total_edges] = exploreConnectedComponent(adj, visited, neighbor);
//                 total_nodes += neighbor_total_nodes;
//                 total_edges += neighbor_total_edges;
//             }
//         }
//         return { total_nodes, total_edges };
//     }

// public:
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for (const auto& edge: edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         // DFS for the unvisited node
//         int complete_connected_components = 0;
//         vector<bool> visited(n, false);
        
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 auto [total_nodes, total_edges] = exploreConnectedComponent(adj, visited, i);
//                 // we will count the edges twice for the undirected graph
//                 total_edges /= 2;
//                 if (total_edges == total_nodes * (total_nodes - 1) / 2) {
//                     complete_connected_components++;
//                 }
//             }
//         }

//         return complete_connected_components;
//     }
// };


// Dry Run

// test case: n = 1, edges = []
// trace:
// adj = [[]]
// complete_connected_components = 0
// visited = [f]
// i = 0
//   > exploreConnectedComponent(i=0)
//      - visited[0] = t
//      - total_nodes = 1
//      - total_edges = 0
//      < { 1, 0 }
//   cond: 0 == 1 * (1 - 0) / 2? yes -> complete_connected_components = 1
// < 1

// test case: n = 3, edges = [[0,1]]
// trace:
// adj = [[],[],[]]
//   - edge[0] = 1, edge[1] = 0
//   - adj[0] = [1], adj[1] = [0]
//   < adj = [[1],[0],[]]
// complete_connected_components = 0
// visited = [f,f,f]
// i = 0
//   > exploreConnectedComponent(i=0)
//      - visited[0] = true
//      - total_nodes = 1
//      - total_edges = 0
//      - neighbor = 1
//      - total_edges = 1
//      > exploreConnectedComponent(i=1)
//          - visited[1] = true
//          - total_nodes = 1
//          - total_edges = 0
//          < return { 1, 0 }
//      - total_nodes = 1 + 1 = 2
//      - total_edges = 1 + 0 = 1
//  cond: 1 == 2 * (2 - 1) / 2? yes -> complete_connected_components = 1
// i = 1
// i = 2
//   > exploreConnectedComponent(i=2)
//      - visited[0] = true
//      - total_nodes = 1
//      - total_edges = 0
//      < return { 1, 0 }
//  cond: 1 == 1 * (1 - 0) / 2? yes -> complete_connected_components = 2
// < return 2


// Evaluation
// V = n, E = # edges
// Time: O(V + E)
// - it takes O(V + E) to build adj
// - for DFS, we will visit every node once and every edge twice. So it will take O(V + 2E)
// Space: O(V + E)
// - it takes O(V + E) for adj
// - for DFS, the recursion stack will be O(V) in worst case


// Submit Errors

// Wrong Answer
// mistake for counting the edges