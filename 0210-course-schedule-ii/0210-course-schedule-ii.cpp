class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector<vector<int>> adj(numCourses);

        for (auto pre: prerequisites) {
            in_degree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr_course = q.front();
                q.pop();
                ans.push_back(curr_course);

                for (int next_course: adj[curr_course]) {
                    in_degree[next_course]--;
                    if (in_degree[next_course] == 0) {
                        q.push(next_course);
                    }
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};