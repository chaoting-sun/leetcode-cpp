class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        cells = m * n
        
        left = 0
        right = n - 1
        top = 0
        bottom = m - 1

        ans = []

        while left <= right and top <= bottom:
            # go right
            for j in range(left, right + 1):
                ans.append(matrix[top][j])
            top += 1

            # go down
            for i in range(top, bottom + 1):
                ans.append(matrix[i][right])
            right -= 1

            # go left
            if top <= bottom:
                for j in range(right, left - 1, -1):
                    ans.append(matrix[bottom][j])
                bottom -= 1
            
            # go up
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    ans.append(matrix[i][left])
                left += 1

        return ans