// Understand

// 1. What is the range of n. can n be 0?
//  - 1 <= n <= 10^4
// 2. What is the range of lenth of edges
//  - 0 <= n <= 10^4 - 1
// 3. May the input be wrong, such as that a node connects to itself?
//  - No

// Match and Plan

// There is at least one node that is at the endpoint of of the diameter.
// A naive solution is to BFS from each of the node and find the maximum
// distance, but it will take O(n^2) time, which is inefficient.
// Another method is that, we randomly pick a node and do a DFS, then, from
// the node with the longest distance, we do another DFS again.
// The diameter is the distance between the endpoint nodes. The time
// complexity will decrease to O(n).


// Implementation

class Solution {
private:
    // return the distance
    int Dfs(const vector<vector<int>>& adjacency_list, vector<bool>& visited, int current_node, int& last_node, int distance, int& max_distance) {
        visited[current_node] = true;
        if (distance > max_distance) {
            max_distance = distance;
            last_node = current_node;
        }

        for (int next_node: adjacency_list[current_node]) {
            if (!visited[next_node]) {
                Dfs(adjacency_list, visited, next_node, last_node, distance + 1, max_distance);
            }
        }
        return max_distance;
    }

public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        // build an adjacency list
        vector<vector<int>> adjacency_list(n);
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
        }

        // Start from the first node and do DFS
        vector<bool> visited(n);
        int first_node = 0;
        int last_node = 0;
        int distance = 0;
        int max_distance = 0;
        Dfs(adjacency_list, visited, first_node, last_node, distance, max_distance);

        // DFS again from the last node
        for (int i = 0; i < n; i++) visited[i] = false;
        first_node = last_node;
        distance = 0;
        max_distance = 0;
        Dfs(adjacency_list, visited, first_node, last_node, distance, max_distance);
        
        return max_distance;
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
    // Dfs(current_node=1, last_node=0, distance=1, max_distance=0)
    // visited[1] = true
    // last_node = 1
    // max_distance = 1
// ------
    // Dfs(current_node=2, last_node=1, distance=1, max_distance=1)
    // visited[2] = true
    // last_node = 2
    // max_distance = 1
// ------
// ------
// first_node = 1
// distance = 0
// max_distance = 0
// ------
    // Dfs(current_node=1, last_node=1, distance=0, max_distance=0)
    // visited[1] = true
    // last_node = 1
    // max_distance = 0
    // ------
        // Dfs(current_node=0, last_node=1, distance=1, max_distance=0)
        // visited[0] = true
        // last_node = 0
        // max_distance = 1
        // ------
            // Dfs(current_node=2, last_node=0, distance=2, max_distance=1)
            // visited[2] = true
            // last_node = 0
            // max_distance = 2
// return max_distance (2)


// Evaluate

// Time complexity: O(E + V) = O(V)
// Space complexity: O(E + V) = O(V)


// Submit Error

// next_node?
// last_node = next_node;
// last_node = current_node;

// wrong answer
