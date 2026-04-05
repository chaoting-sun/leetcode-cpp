class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # build DAG and indegree
        courses = [[] for _ in range(numCourses)]
        indegree = [0 for _ in range(numCourses)]
        for pre in prerequisites:
            courses[pre[1]].append(pre[0])
            indegree[pre[0]] += 1

        # gather those with indegree 0
        q = deque()
        for i, v in enumerate(indegree):
            if v == 0:
                q.append(i)

        # multi-source bfs
        taken_count = 0

        while q:
            curr_course = q.popleft()
            taken_count += 1
            for next_course in courses[curr_course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)

        return taken_count == numCourses