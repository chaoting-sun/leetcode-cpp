# monotonic decreasing stack

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = []
        n = len(position)
        for i in range(n):
            time = (target - position[i]) / speed[i]
            cars.append((position[i], time))
        
        cars.sort()

        stk = [] # time to arrive
        for i in range(n):
            while stk and stk[-1] <= cars[i][1]:
                stk.pop()
            stk.append(cars[i][1])

        return len(stk)

'''
base case:
target = 1, position = [0], speed = [1]
trace:
cars = [(0,1)]
stk = []
stk = [1]
< returns 1

test case:
target = 4, position = [0,1,2], speed = [2,1,1]
trace:
time = [2,3,2]
cars = [(0,2), (1,3), (2,2)]
stk = []
stk = [2]
stk = []
stk = [3]
stk = [3,2]
< returns 2
'''