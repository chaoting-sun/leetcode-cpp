// find all nodes that are not in any cycles in a DAG.

class Solution {
private:
    int dfs(const vector<vector<int>>& graph, vector<int>& node_state, int curr) {
        // only handle unvisited node
        if (node_state[curr] != -1) {
            return node_state[curr];
        }

        // mark as visiting
        node_state[curr] = 0;
        
        bool is_safe = true;
        for (int next: graph[curr]) {
            // explore the unvisited node
            if (node_state[next] == -1) {
                int next_state = dfs(graph, node_state, next);
                if (next_state == 2) is_safe = false;
            // find the visiting node or unsafe node -> curr is unsafe
            } else if (node_state[next] == 0 || node_state[next] == 2) {
                is_safe = false;
            }
        }

        node_state[curr] = is_safe ? 1 : 2;
        return node_state[curr];
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {};

        // -1: unvisited
        // 0: is visiting
        // 1: visited and is safe
        // 2: visited and is unsafe
        vector<int> node_state(n, -1);

        for (int i = 0; i < n; i++) {
            if (node_state[i] == -1) {
                dfs(graph, node_state, i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (node_state[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// test case:
// graph = [[1],[2],[1]]
// node_state = [2,2,2]
// trace:
// i = 0
// dfs(curr=0)
//  is_safe=true
//  next_state=dfs(next=1)
//      is_safe=true
//          next_state=dfs(next=2)
//              is_safe=false
//              < returns 2
//      is_safe=false
//      < returns 2
//  is_safe=false
//  < returns 2
// < returns []

// base case:
// graph = [[]]
// node_state = [1]
// trace:
// i = 0
// dfs(curr=0)
//  < returns 1
// ans = [0]
// < returns [0]

// base case:
// graph = [[0]]
// node_state = [2]
// trace:
// i = 0
// dfs(curr=0)
//  is_safe = false
//  < returns 2
// ans = []
// < returns []
