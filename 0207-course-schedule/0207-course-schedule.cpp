// topological sort
// Kadane's algorithm (?)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_order(numCourses);
        vector<int> in_degree(numCourses);

        for (auto& courses: prerequisites) {
            // b is a's prerequisite
            course_order[courses[1]].push_back(courses[0]);
            in_degree[courses[0]]++;
        }

        queue<int> courses;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) courses.push(i);
        }
        
        int taken_courses = 0;

        while (!courses.empty()) {
            int current_course = courses.front();
            courses.pop();
            taken_courses++;

            for (int next_course: course_order[current_course]) {
                // has been processed or pushed to courses
                if (in_degree[next_course] == 0) continue;
                in_degree[next_course]--;
                if (in_degree[next_course] == 0) {
                    courses.push(next_course);   
                }
            }
        }
        return taken_courses == numCourses;
    }
};

// test case: numCourses = 2, prerequisites = [[1,0], [0,1]] -> no
// trace:
// in_degree[0] = 1, in_degree[1] = 1
// < returns 0 == 2

// test case: numCourses = 3, prerequisites = [[1,0], [1,2]] -> yes
// trace:
// course_order[0] = [1], in_degree[1] = 1
// course_order[2] = [1], in_degree[1] = 2
// courses = [0,2]
// while loop:
//  current = 0
//  courses = [2]
//  taken = 1
//      next = 1
//      in_degree[1] = 1
//  current = 2
//  courses = []
//  taken = 2
//      next = 1
//      in_degree[1] = 0
//      courses = [1]
//  current = 1
//  courses = []
//  taken = 3
//  < returns 3 == 3

// Submit Error
// courses.push_back(i); -> courses.push(i);