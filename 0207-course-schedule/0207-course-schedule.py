class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # build DAG and indegree
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for course, pre in prerequisites:
            graph[pre].append(course)
            indegree[course] += 1

        # gather those with indegree 0
        q = deque(i for i, v in enumerate(indegree) if v == 0)

        # multi-source bfs
        completed = 0

        while q:
            curr_course = q.popleft()
            completed += 1
            for next_course in graph[curr_course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)

        return completed == numCourses