class MinStack:

    def __init__(self):
        self.stk = []
        self.min_stk = []

    def push(self, val: int) -> None:
        self.stk.append(val)
        last_min = self.min_stk[-1] if len(self.min_stk) else inf
        self.min_stk.append(min(last_min, val))

    def pop(self) -> None:
        if (self.stk) == 0:
            return -1
        self.stk.pop()
        self.min_stk.pop()

    def top(self) -> int:
        if len(self.stk) == 0:
            return -1
        return self.stk[-1]

    def getMin(self) -> int:
        if len(self.stk) == 0:
            return -1
        return self.min_stk[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()