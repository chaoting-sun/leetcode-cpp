# bfs

from collections import deque

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m, n = len(image), len(image[0])

        origin_color = image[sr][sc]
        visited = [[False for _ in range(n)] for _ in range(m)]

        q = deque()
        q.append((sr, sc))
        visited[sr][sc] = True

        while q:
            prev_sr, prev_sc = q.popleft()
            image[prev_sr][prev_sc] = color
            
            for d_row, d_col in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                new_sr = prev_sr + d_row
                new_sc = prev_sc + d_col
                if 0 <= new_sr < m and 0 <= new_sc < n and not visited[new_sr][new_sc] and image[new_sr][new_sc] == origin_color:
                    q.append((new_sr, new_sc))
                    visited[new_sr][new_sc] = True
        
        return image