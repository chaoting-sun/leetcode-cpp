from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        seen = defaultdict(int)
        max_len = 0
        for v in nums:
            if v in seen:
                continue

            left_len = seen[v - 1] if v - 1 in seen else 0
            right_len = seen[v + 1] if v + 1 in seen else 0
            if v - 1 in seen and v + 1 in seen:
                seen[v] = seen[v - left_len] = seen[v + right_len] = left_len + right_len + 1
            elif v - 1 in seen:
                seen[v] = seen[v - left_len] = left_len + 1
            elif v + 1 in seen:
                seen[v] = seen[v + right_len] = right_len + 1
            else:
                seen[v] = 1
            max_len = max(max_len, seen[v])
        return max_len


'''
test case: [1,3,2]
seen = {}
v = 1
    seen = {1:1}
    max_len = 1
v = 3
    seen = {1:1, 3:1}
    max_len = 1
v = 2
    left_len = 1
    right_len = 1
    seen[2] = seen[1] = seen[3] = 3
    max_len = 3
< returns max_len = 3
'''