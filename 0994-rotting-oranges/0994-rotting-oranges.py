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

        minutes = 0
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        while q and fresh_oranges > 0:
            level_size = len(q)
            
            for _ in range(level_size):
                i, j = q.popleft()
                for di, dj in directions:
                    newi = i + di
                    newj = j + dj
                    if newi < 0 or newi >= m or newj < 0 or newj >= n or grid[newi][newj] != 1:
                        continue

                    fresh_oranges -= 1
                    grid[newi][newj] = 2
                    q.append((newi, newj))

            minutes += 1

        return minutes if fresh_oranges == 0 else -1