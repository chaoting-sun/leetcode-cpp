// ## Understand

// May I ask the range of n?
//  - 1 <= n <= 5000
// May I ask the size range of relations?
//  - 1 <= relations.length <= 5000
// Can the input be invalid, such as n is a negative value, or a class appears in the prevCourse and nextCourse in a relation
//  - prevCourse_i != nextCourse_i

// forgot to ask:
//  - are all pairs unique -> yes


// ## Match

// It is a topological sort problem because the courses form a directional acyclic graph and we want to find if there is a cycle.
// If there is a cycle, no indegree of the courses in this cycle is 0, then there is no way to take all the courses.


// ## Plan

// I will divide my implementation into three parts:
// first, I compute the adjacency list using the relations. Second, I compute the indegree of each node. Third, I start a multi-source
// BFS from those nodes with 0 indegree using a queue, and handle the nodes layer by layer. if a node is processed, then I decrease the
// indegree of its adjacent nodes, after which the nodes will be taken to be processed if their degrees become 0. A variable semester_count
// will be used to calculate the number of layers during the BFS.
// I will use a variable courses_taken to represent the courses that have been processed. After BFS, if course_taken is not equal to n, then
// return -1, else return semester_count


// ## Implementation

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n + 1); // DAG
        vector<int> in_degree(n + 1);
        for (const auto& relation: relations) {
            adj[relation[0]].push_back(relation[1]);
            in_degree[relation[1]]++;
        }

        // multi-source BFS
        queue<int> courses;
        int semesters_count = 0;
        int courses_taken = 0;
        
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) courses.push(i);
        }

        while (!courses.empty()) {
            int size = courses.size();
            semesters_count++;
   
            while (size--) {
                int current_course = courses.front();
                courses.pop();
                courses_taken++;
                for (const int& next_course: adj[current_course]) {
                    in_degree[next_course]--;
                    if (in_degree[next_course] == 0) {
                        courses.push(next_course);
                    }
                }
            }
        }
        
        return courses_taken == n ? semesters_count : -1;
    }
};


// Evaluation
// R: length of relations
// Time: O(n + R)
//  - adj: O((n+1) + R) = O(n + R)
//  - BFS: O(n + R). Each node and edge will be visited at most
// Space: O(n + R)
//  - adj: O((n+1) + R) = O(n + R)
//  - BFS: O(n + 1) for queue at most when there is no edge


// Dry Run

// Test case (base case): n = 1, relations = []
// > minimumSemesters(n = 1, relations = [])
//     in_degree = [0,0]
//     semesters_count = 0, courses_taken = 0
//     > BFS:
//         - courses = [1]
//         - size = 1
//         - semesters_count = 1
//             - current_course = 1
//             - courses = []
//             - courses_taken = 1
//         - size = 0
//     > 1

// Test case (valid case): n = 3, relations = [[1,2], [2,3]]
// > minimumSemesters(n = 3, relations = [[1,2], [2,3]])
//     > build adj
//         adj[1].push_back(2)
//         adj[2].push_back(3)
//         < adj = [[],[2],[3],[]]
//     > build in_degree
//         in_degree[2] = 1
//         in_degree[3] = 1
//         < in_degree = [0,0,1,1]
//     > BFS:
//         - courses = [1] -> not empty
//             - size = 1
//             - semesters_count = 1
//             - while loop: size = 1
//                 - current_course = 1
//                 - courses = []
//                 - courses_taken = 1
//                 - next_course = 2
//                 - in_degree[2] = 0
//                 - course = [2]
//         - courses = [2] -> not empty
//             - size = 1
//             - semesters_count = 2
//             - while loop: size = 1
//                 - current_course = 2
//                 - courses = []
//                 - courses_taken = 2
//                 - next_course = 3
//                 - in_degree[3] = 0
//                 - course = [3]
//         - courses = [3] -> not empty
//             - size = 1
//             - semesters_count = 3
//             - while loop: size = 1
//                 - current_course = 3
//                 - courses = []
//                 - courses_taken = 3
//         - courses = [3] -> empty -> break

//     < courses_taken = 3, n = 3 return 3

// Test case (invald case: cycle): n = 3, relations = [[1,2],[2,3],[3,1]]
// > minimumSemesters(n = 3, relations = [[1,2],[2,3],[3,1]])
//     > build adj
//         adj[1].push_back(2)
//         adj[2].push_back(3)
//         adj = [[],[2],[3],[1]]
//     > build in_degree
//         in_degree[2] = 1
//         in_degree[3] = 1
//         in_degree[1] = 1
//     > BFS:
//         courses = [] -> empty -> break

//     > course_taken = 0, n = 3 -> return -1


// Test case (valid case): n = 3, relations = [[1,3],[2,3]]
// > minimumSemesters(n = 3, relations = [[1,3],[2,3]])
//     > build adj
//         < adj[[],[3],[3],[]]
//     > build in_degree
//         < in_degree = [0,0,0,2]
//     > BFS:
//         - courses = [1,2]
//             - size = 2
//             - semesters_count = 1
//             - while loop: size = 2
//                 - current_course = 1
//                 - courses = [2]
//                 - courses_taken = 1
//                 - next_course = 3
//                 - in_degree[3] = 1
//             - while loop: size = 1
//                 - current_course = 2
//                 - courses = []
//                 - courses_taken = 2
//                 - next_course = 3
//                 - in_degree[3] = 0
//                 - courses = [3]
//             - while loop: size = 0 -> break
//         - courses = [3]
//             - size = 1
//             - semesters_count = 2
//             - while loop: size = 1
//                 - current_course = 3
//                 - courses = []
//                 - courses_taken = 3
//                 - next_course -> x
//             - while loop: size = 0 -> break
//     < return 2

// Submit Error

// for (const int& relation: relations) {
// to
// for (const auto& relation: relations) {

// courses.push(next_courses);
// to
// courses.push(next_course);

// wrong answer for n == 3, relations = [[1,3],[2,3]]
// if (in_degree[i]) courses.push(i);
// to
// if (in_degree[i] == 0) courses.push(i);