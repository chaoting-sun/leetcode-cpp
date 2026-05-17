class Solution:
    def dfs(self, grid: List[List[str]], i: int, j: int):
        m, n = len(grid), len(grid[0])
        grid[i][j] = '#'
        for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            newi = i + di
            newj = j + dj
            if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == '1':
                self.dfs(grid, newi, newj)
    
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1
        return count