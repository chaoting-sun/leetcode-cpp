from collections import defaultdict

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        seen = {}
        max_len = 0
        for v in nums:
            if v in seen:
                continue

            left_len = seen.get(v - 1, 0)
            right_len = seen.get(v + 1, 0)

            new_len = left_len + right_len + 1
            seen[v] = new_len
            seen[v - left_len] = new_len
            seen[v + right_len] = new_len
            
            max_len = max(max_len, seen[v])
        return max_len