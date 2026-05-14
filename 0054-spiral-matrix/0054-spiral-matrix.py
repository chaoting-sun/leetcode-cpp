class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        cells = m * n
        
        left_most = 0
        right_most = n - 1
        top_most = 1
        bottom_most = m - 1

        ans = [matrix[0][0]]
        ci = 0
        cj = 0
        count = 1

        while True:
            # go right
            while cj < right_most:
                cj += 1
                ans.append(matrix[ci][cj])
                count += 1
            right_most -= 1
            if count == cells:
                break

            # go down
            while ci < bottom_most:
                ci += 1
                ans.append(matrix[ci][cj])
                count += 1
            bottom_most -= 1
            if count == cells:
                break

            # go left
            while cj > left_most:
                cj -= 1
                ans.append(matrix[ci][cj])
                count += 1
            left_most += 1
            if count == cells:
                break
            
            # go up
            while ci > top_most:
                ci -= 1
                ans.append(matrix[ci][cj])
                count += 1
            top_most += 1
            if count == cells:
                break

        return ans