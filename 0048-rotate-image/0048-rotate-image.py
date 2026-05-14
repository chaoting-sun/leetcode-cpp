class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        
        for i in range(m // 2):
            for j in range(n):
                matrix[i][j], matrix[m - 1 - i][j] = matrix[m - 1 - i][j], matrix[i][j]
        
        for i in range(1, m):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

"""
test case:
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]
trace:
m = n = 3
matrix = [[7,8,9],
          [4,5,6],
          [1,2,3]]
i = 0
    j = 0, swap matrix[0][0], matrix[2][0]
    j = 1, swap matrix[0][1], matrix[2][1]
    j = 2, swap matrix[0][2], matrix[2][2]
i = 1
    j = 0
i = 2
    j = 0
    j = 1
"""