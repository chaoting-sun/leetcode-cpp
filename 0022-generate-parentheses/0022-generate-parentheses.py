class Solution:
    def backtracking(self, ans: List[str], curr: List[str], n: int, left: int, right: int) -> None:
        if len(curr) == 2 * n:
            ans.append(''.join(curr))
            return
        
        if left == n:
            ans.append(''.join(curr + [')'] * (left - right)))
            return

        # add (
        curr.append('(')
        self.backtracking(ans, curr, n, left + 1, right)
        curr.pop()

        # add )
        if left > right:
            curr.append(')')
            self.backtracking(ans, curr, n, left, right + 1)
            curr.pop()


    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        curr = []
        self.backtracking(ans, curr, n, 0, 0)
        return ans