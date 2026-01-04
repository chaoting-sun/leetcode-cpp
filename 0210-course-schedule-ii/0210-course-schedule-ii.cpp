class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_order(numCourses);
        vector<int> in_degree(numCourses);

        for (auto& courses: prerequisites) {
            // b is a's prerequisite
            course_order[courses[1]].push_back(courses[0]);
            in_degree[courses[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        vector<int> results;

        while (!q.empty()) {
            int current_course = q.front();
            q.pop();
            results.push_back(current_course);
            
            if (results.size() == numCourses) break;

            for (int next_course: course_order[current_course]) {
                // has been processed or pushed to q
                if (in_degree[next_course] == 0) continue;
                in_degree[next_course]--;
                if (in_degree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }

        if (results.size() == numCourses) {
            return results;
        }
        return {};
        // return results.size() == numCourses ? results : {};
    }
};
