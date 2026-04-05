class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # build DAG and indegree
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for course, pre in prerequisites:
            graph[pre].append(course)
            indegree[course] += 1

        # gather those with indegree 0
        q = deque(i for i, v in enumerate(indegree) if v == 0)

        # multi-source bfs
        order = []

        while q:
            curr_course = q.popleft()
            order.append(curr_course)
            for next_course in graph[curr_course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)

        return order if len(order) == numCourses else []