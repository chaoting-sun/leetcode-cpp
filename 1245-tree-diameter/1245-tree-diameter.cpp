// Understand

// 1. What is the range of n. can n be 0?
//  - 1 <= n <= 10^4
// 2. What is the range of lenth of edges
//  - 0 <= n <= 10^4 - 1
// 3. May the input be wrong, such as that a node connects to itself?
//  - No

// Match and Plan

// There is at least one node that is at the endpoint of the diameter.
// A naive solution is to BFS from each of the node and find the maximum
// distance, but it will take O(n^2) time, which is inefficient.
// Another method is that, we randomly pick a node and do a DFS, then, from
// the node with the longest distance, we do another DFS again.
// The diameter is the distance between the endpoint nodes. The time
// complexity will decrease to O(n).


// Implementation

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int global_max_height = 0;

        auto dfs = [&](auto&& self, int curr, int parent) -> int {
            int max_height_1 = 0;
            int max_height_2 = 0;

            for (int neighbor: adj[curr]) {
                if (neighbor == parent) continue;

                int child_height = 1 + self(self, neighbor, curr);
                if (child_height > max_height_1) {
                    max_height_2 = max_height_1;
                    max_height_1 = child_height;
                } else if (child_height > max_height_2) {
                    max_height_2 = child_height;
                }

                global_max_height = max(global_max_height, max_height_1 + max_height_2);
            }
            return max_height_1;
        };

        dfs(dfs, 0, -1);

        return global_max_height;
    }
};

// Review

// edge case: edges = []
// n = 1
// adjacency_list
// 0 -> x
// ------
// Dfs(current_node=0, last_node=0, distance=0, max_distance=0)
// visited[0] = true
// last_node = 0
// max_distance = 0
// ------
// Dfs(current_node=0, last_node=0, distance=0, max_distance=0)
// the same as the first time -> max_distance = 0

// edges = [[0,1],[0,2]]
// n = 3
// adjacency_list
// 0 -> 1, 2
// 1 -> 0
// 2 -> 0
// ------
// Dfs(current_node=0, last_node=0, distance=0, max_distance=0)
// visited[0] = true
// last_node = 0
// max_distance = 0
// ------
//     Dfs(current_node=1, last_node=0, distance=1, max_distance=0)
//     visited[1] = true
//     last_node = 1
//     max_distance = 1
// ------
//     Dfs(current_node=2, last_node=1, distance=1, max_distance=1)
//     visited[2] = true
//     last_node = 2
//     max_distance = 1
// ------
// ------
// first_node = 1
// distance = 0
// max_distance = 0
// ------
//     Dfs(current_node=1, last_node=1, distance=0, max_distance=0)
//     visited[1] = true
//     last_node = 1
//     max_distance = 0
//     ------
//         Dfs(current_node=0, last_node=1, distance=1, max_distance=0)
//         visited[0] = true
//         last_node = 0
//         max_distance = 1
//         ------
//             Dfs(current_node=2, last_node=0, distance=2, max_distance=1)
//             visited[2] = true
//             last_node = 0
//             max_distance = 2
// return max_distance (2)


// Evaluate

// Time complexity: O(E + V) = O(V)
// Space complexity: O(E + V) = O(V)


// Submit Error

// next_node?
// last_node = next_node;
// to
// last_node = current_node;

// wrong answer: the last node does not neccessarily store the node that achieved
// the maximum distance found so far
// last_node = current_node;
// max_distance = max(max_distance, distance);
// to
// if (distance > max_distance) {
//     max_distance = distance;
//     last_node = current_node;
// }
