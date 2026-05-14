class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        bracket_map = {
            '{': '}',
            '[': ']',
            '(': ')'
        }

        for ch in s:
            # left bracket -> append to stk and wait for its right bracket
            if ch in bracket_map:
                stk.append(ch)
                continue

            # right bracket
            # match -> remove the top bracket
            if stk and bracket_map[stk[-1]] == ch:
                stk.pop()
            # does not match
            else:
                return False
    
        return len(stk) == 0