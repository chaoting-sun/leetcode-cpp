# number of '(' >= number of ')'

class Solution:
    def recursion(self, n, left, right, candidates, ans):
        # base case
        if n == left:
            ans.append("".join(candidates + [')'] * (left - right)))
            return

        if left > right:
            candidates.append(')')
            self.recursion(n, left, right + 1, candidates, ans)
            candidates.pop()

        candidates.append('(')
        self.recursion(n, left + 1, right, candidates, ans)
        candidates.pop()            


    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        candidates = []
        self.recursion(n, 0, 0, candidates, ans)
        return ans
