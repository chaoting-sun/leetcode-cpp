# class Solution:
#     def setZeroes(self, matrix: List[List[int]]) -> None:
#         """
#         Do not return anything, modify matrix in-place instead.
#         """
#         m, n = len(matrix), len(matrix[0])
        
#         rows = [False] * m
#         cols = [False] * n

#         for i in range(m):
#             for j in range(n):
#                 if matrix[i][j] == 0:
#                     rows[i] = True
#                     cols[j] = True
        
#         for i in range(m):
#             for j in range(n):
#                 if rows[i] or cols[j]:
#                     matrix[i][j] = 0


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])

        first_row_has_0 = False
        first_col_has_0 = False

        for i in range(m):
            if matrix[i][0] == 0:
                first_col_has_0 = True
                break

        for j in range(n):
            if matrix[0][j] == 0:
                first_row_has_0 = True
                break

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if first_col_has_0:
            for i in range(m):
                matrix[i][0] = 0
        if first_row_has_0:
            for j in range(n):
                matrix[0][j] = 0