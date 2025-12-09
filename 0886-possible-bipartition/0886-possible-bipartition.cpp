// Understand

// 1. Is the n larger than 1. n should be at least 1 to split the people into two groups
//  - 1 <= n <= 2000
// 2. Is it possible for anyone to dislike himself?
//  - "Each person may dislike some other people", so it's not
// 3. What is the range of n?
//  - 1 <= n <= 2000
// 4. What is the size of dislikes?
//  - 1 <= dislikes.length <= 10^4


// Match & Plan

// A naive approach may be that we split the people into (1, n - 1) for every possibilies,
// and use the dislikes to check if this split is valid. But this will takes very long time
// owning to the large quantity of possibilities. For example, to split into (k, n-k), the
// combinations are C^n_{n-k}.
// This is two coloring problem that a set of nodes need to be splitted into two groups.
// All nodes are uncolored initially, and will be set to red color or blue color to represent
// two groups.
// The process I will take is to build an adjacency list, treating the person as node and
// the relationship of the dislikes as edges. Noting that it is an undirected graph because
// the relationship is bidirectional. After building the list, I iterate through the list,
// for the node that is uncolored, I do DFS from this node, and set its color as red. Then
// I iterate through its connected nodes, do DFS again for those uncolored ones and assign
// the color as blue. Oppositely, when the current node is assigned as blue, then we'll the
// uncolored adjacent nodes as red. during iteration, for any colored one, if its color is
// different from what we are going to assign it as, then it means we cannot split the people
// into two groups.


// Implementation

class Solution {
private:
    bool Dfs(const vector<vector<int>>& adj, vector<int>& colors, int u, int current_color) {
        // set the color
        colors[u] = current_color;

        // iterate all the adjacent nodes
        // each node
        //  - uncolored -> color it
        //  - colored -> check if it is valid. if not, return false
        for (const auto& v: adj[u]) {
            if (colors[v] == 0) {
                bool is_valid = Dfs(adj, colors, v, -current_color);
                if (!is_valid) return false;
            } else if (colors[v] != -current_color) {
                return false;
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // build an adjacency list
        // notice that it's a undirected graph
        vector<vector<int>> adj(n + 1);
        for (const auto& dislike: dislikes) {
            int u = dislike[0], v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // iterate adj and do dfs if the current node is uncolored
        vector<int> colors(n + 1, 0);
        int first_color = -1;
        for (int i = 1; i <= n; i++) {
            if (colors[i] == 0) {
                bool is_split_possible = Dfs(adj, colors, i, first_color);
                if (!is_split_possible) return false;
            }
        }

        return true;
    }
};

// n = 4, dislikes = [[1,2],[1,3],[2,4]]
// adj
// 1 -> 2 3
// 2 -> 1 4
// 3 -> 1
// 4 -> 2
// colors = [0, 0, 0, 0]
// dfs()
// i == 1, set colors[1] to -1
//   - i == 2, set colors[2] to 1
//     - i == 1, has been to -1 -> valid
//     - i == 4, set colors[4] to -1
//        - i == 2, has been set to 1 -> valid
//   - i == 3, set colors to -1
//     - i == 1, has been set to -1 -> invalid -> return false


// Review

// n = 1, dislikes = []
// return true

// n = 3, dislikes = [[1,2], [2,3], [3,1]]
// adj
// 1 -> 2 3
// 2 -> 1 3
// 3 -> 2 1
// colors: [0, 0, 0]
// dfs()
// i == 1, set colors[2] to -1
//   - i == 2, set colors[2] to 1
//     - i == 1, has been set to -1 -> valid
//     - i == 3, set colors[3] to -1
//       - i == 2, has been set to 1 -> valid
//       - i == 1, has been set to -1 -> invalid -> return false

// n = 3, dislikes = [[1,2]]
// adj
// 1 -> 2
// 2 -> 1
// 3 ->
// colors = [0, 0, 0]
// dfs()
// i == 1, set colors[1] to -1
//   - i == 2, set colors[2] to 1
//     - i == 1, has been to -1 -> valid
// i == 3, set colors[1] to -1
// return true


// Submit Error

// 1. constant argument cannot be modified
// bool Dfs(const vector<vector<int>>& adj, const vector<int>& colors, int u, int current_color) {
//     colors[u] = current_color;
// to
// bool Dfs(const vector<vector<int>>& adj, vector<int>& colors, int u, int current_color) {
//     colors[u] = current_color;

// 2. it is colors, not color
// color[i] == 0
// to
// colors[i] == 0

// 3. labeled from 1 to n
// vector<vector<int>> adj(n);
// to
// vector<vector<int>> adj(n + 1);

// 4. stack-overflow on DFS (fuck)
// Dfs(adj, colors, u, -current_color);
// to
// Dfs(adj, colors, v, -current_color);

// 5. does not return result
// bool Dfs(const vector<vector<int>>& adj, vector<int>& colors, int u, int current_color) {
//     colors[u] = current_color;
//     for (const auto& v: adj[u]) {
//         if (colors[v] == 0) {
//             Dfs(adj, colors, v, -current_color);
//         } else if (colors[v] != -current_color) {
//             return false;
//         }
//     }
//     return true;
// }
// to
// bool Dfs(const vector<vector<int>>& adj, vector<int>& colors, int u, int current_color) {
//     colors[u] = current_color;
//     for (const auto& v: adj[u]) {
//         if (colors[v] == 0) {
//             return Dfs(adj, colors, v, -current_color);
//         } else if (colors[v] != -current_color) {
//             return false;
//         }
//     }
//     return true;
// }