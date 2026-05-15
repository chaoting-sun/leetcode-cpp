class Solution:
    # get area
    def dfs(self, grid: List[List[int]], i: int, j: int) -> None:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != 1:
            return 0
        
        count = 1
        grid[i][j] = 0 # visited

        for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            newi = i + di
            newj = j + dj
            count += self.dfs(grid, newi, newj)
        return count


    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    curr_area = self.dfs(grid, i, j)
                    max_area = max(max_area, curr_area)
        
        return max_area