class Solution:
    def dfs(self, ans: List[str], curr: List[str], n: int, left: int, right: int) -> None:
        if len(curr) == 2 * n:
            ans.append(''.join(curr))
            return
        
        if left == n:
            ans.append(''.join(curr + [')'] * (left - right)))
            return

        # add (
        curr.append('(')
        self.dfs(ans, curr, n, left + 1, right)
        curr.pop()

        # add )
        if left > right:
            curr.append(')')
            self.dfs(ans, curr, n, left, right + 1)
            curr.pop()


    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        curr = []
        self.dfs(ans, curr, n, 0, 0)
        return ans