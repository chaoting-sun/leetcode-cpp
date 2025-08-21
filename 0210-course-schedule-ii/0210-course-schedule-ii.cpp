class Solution {
public:
    // Approach1: Topological Sort by Kahn's Algorithm
    // Time: O(E + V)
    // Space: O(E + V)

    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> in_degree(numCourses);
    //     vector<vector<int>> adj(numCourses);

    //     // Time: O(E)
    //     // Space: O(E + V)
    //     for (auto pre: prerequisites) {
    //         in_degree[pre[0]]++;
    //         adj[pre[1]].push_back(pre[0]);
    //     }

    //     // Time: O(V)
    //     vector<int> ans;
    //     queue<int> q;
    //     for (int i = 0; i < numCourses; i++) {
    //         if (in_degree[i] == 0) {
    //             q.push(i);
    //         }
    //     }

    //     // Time: O(E + V)
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             int curr_course = q.front();
    //             q.pop();
    //             ans.push_back(curr_course);

    //             for (int next_course: adj[curr_course]) {
    //                 in_degree[next_course]--;
    //                 if (in_degree[next_course] == 0) {
    //                     q.push(next_course);
    //                 }
    //             }
    //         }
    //     }

    //     return ans.size() == numCourses ? ans : vector<int>();
    // }

    // Approach2: Topological Sort by DFS
    // Time: O(E + V)
    // Space: O(E + V)

    bool findCycle(vector<vector<int>>& adj, stack<int>& stk, vector<int>& visited, int curr_course) {
        if (visited[curr_course] == 1) return true; // visited a course being visited
        if (visited[curr_course] == 2) return false; // visit a course visited before

        visited[curr_course] = 1;
        for (int next_course: adj[curr_course]) {
            if (findCycle(adj, stk, visited, next_course)) {
                return true;
            }
        }
        visited[curr_course] = 2; // finish visit
        stk.push(curr_course);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        stack<int> stk;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (findCycle(adj, stk, visited, i)) {
                return {};
            }
        }

        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};