from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if numCourses == 0:
            return True
        
        in_degree = [0] * numCourses
        course_orders = [[] for _ in range(numCourses)]

        for pre in prerequisites:
            curr_class = pre[1]
            next_class = pre[0]
            if curr_class == next_class:
                return False
            course_orders[curr_class].append(next_class)
            in_degree[next_class] += 1

        q = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)
        
        taken_courses = 0
        while q:
            curr_class = q.popleft()
            taken_courses += 1
            for next_class in course_orders[curr_class]:
                in_degree[next_class] -= 1
                if in_degree[next_class] == 0:
                    q.append(next_class)
        
        return taken_courses == numCourses