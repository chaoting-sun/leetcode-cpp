# dfs

# class Solution:
#     def dfs(self, image: List[List[int]], sr: int, sc: int, color: int, origin_color: int):
#         if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]) or image[sr][sc] != origin_color:
#             return
#         image[sr][sc] = color
#         self.dfs(image, sr + 1, sc, color, origin_color)
#         self.dfs(image, sr - 1, sc, color, origin_color)
#         self.dfs(image, sr, sc + 1, color, origin_color)
#         self.dfs(image, sr, sc - 1, color, origin_color)
    
#     def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
#         m, n = len(image), len(image[0]) 
#         origin_color = image[sr][sc]
#         if origin_color == color:
#             return image

#         self.dfs(image, sr, sc, color, origin_color)
#         return image


# bfs

from collections import deque

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m, n = len(image), len(image[0])

        origin_color = image[sr][sc]
        if origin_color == color:
            return image

        q = deque()
        q.append((sr, sc))

        while q:
            prev_sr, prev_sc = q.popleft()
            image[prev_sr][prev_sc] = color
            
            for d_row, d_col in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                new_sr = prev_sr + d_row
                new_sc = prev_sc + d_col
                if 0 <= new_sr < m and 0 <= new_sc < n and image[new_sr][new_sc] == origin_color:
                    q.append((new_sr, new_sc))
        
        return image