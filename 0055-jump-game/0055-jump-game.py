from collections import deque

# class Solution:
#     def canJump(self, nums: List[int]) -> bool:
#         n = len(nums)
#         farthest_loc = 0
#         curr_loc = 0

#         while curr_loc <= farthest_loc:
#             farthest_loc = max(farthest_loc, curr_loc + nums[curr_loc])
#             if farthest_loc >= n - 1:
#                 return True
#             curr_loc += 1
    
#         return False

"""
test: nums = [2,3,1,1,4]
trace:
fl = 0, cl = 0
loop 0 <= 0
    fl = 2
    cl = 1
loop 1 <= 2
    fl = 4
    < returns True
"""

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        farthest_loc = 0

        for curr_loc in range(n):
            if farthest_loc < curr_loc:
                break
            
            farthest_loc = max(farthest_loc, curr_loc + nums[curr_loc])
            if farthest_loc >= n - 1:
                return True

        return False