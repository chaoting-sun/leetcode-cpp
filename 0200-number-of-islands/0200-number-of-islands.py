class Solution:
    def search(self, grid, x, y):
        m, n = len(grid), len(grid[0])

        grid[x][y] = '#'
        for dir in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx = x + dir[0]
            ny = y + dir[1]
            if nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == '1':
                self.search(grid, nx, ny)
    
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        m, n = len(grid), len(grid[0])

        for x in range(m):
            for y in range(n):
                if grid[x][y] == '1':
                    self.search(grid, x, y)
                    count += 1
        
        return count