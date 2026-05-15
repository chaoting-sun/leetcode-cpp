class Solution:
    def operate(self, op: str, prev: int, curr: int):
        if op == '+':
            return prev + curr
        elif op == '-':
            return prev - curr
        elif op == '*':
            return prev * curr
        else:
            ans = prev / curr
            return floor(ans) if ans >= 0 else ceil(ans)

    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        operators = set(['+', '-', '*', '/'])

        for token in tokens:
            if token in operators:
                curr = stk.pop()
                prev = stk.pop()
                stk.append(self.operate(token, prev, curr))
            else:
                stk.append(int(token))

        return stk[0]

'''
test case: 2 3 4 * -
trace:
stk = []
stk = [2,3,4]
token = '*'
    curr = 4
    prev = 3
    stk = [2,12]
token = '-'
    curr = 12
    prev = 3
    stk = [-9]
< returns -9
'''