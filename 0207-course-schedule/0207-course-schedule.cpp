class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> courses_order(numCourses); // class A -> classes after class A

        for (auto pre: prerequisites) {
            indegree[pre[0]]++;
            courses_order[pre[1]].push_back(pre[0]);
        }

        queue<int> courses_queue;
        int count = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                courses_queue.push(i);
            }
        }

        while (!courses_queue.empty()) {
            int size = courses_queue.size();
            count += size;

            for (int i = 0; i < size; i++) {
                int current_course = courses_queue.front();
                courses_queue.pop();

                for (int next_course: courses_order[current_course]) {
                    indegree[next_course]--;
                    if (indegree[next_course] == 0) {
                        courses_queue.push(next_course);
                    }
                }
            }
        }

        return count == numCourses;
    }
};