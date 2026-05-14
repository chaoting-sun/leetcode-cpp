from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        m, n = len(grid), len(grid[0])
        fresh_oranges = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh_oranges += 1

        if fresh_oranges == 0:
            return 0

        minutes = 0
        rotten_oranges = 0

        while q:
            n_rotten = len(q)
            has_fresh = False
            for _ in range(n_rotten):
                i, j = q.popleft()
                for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    newi = i + di
                    newj = j + dj
                    if newi < 0 or newi >= m or newj < 0 or newj >= n or grid[newi][newj] != 1:
                        continue

                    has_fresh = True
                    rotten_oranges += 1
                    grid[newi][newj] = 2
                    q.append((newi, newj))

            if has_fresh:
                minutes += 1

        return minutes if fresh_oranges == rotten_oranges else -1